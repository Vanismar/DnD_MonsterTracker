#include "FlowLayout.h"

#include <QtWidgets>

FlowLayout::FlowLayout(QWidget *parent, int margin, int hSpacing, int vSpacing)
    : QLayout(parent), m_hSpace(hSpacing), m_vSpace(vSpacing)
{
    setContentsMargins(margin, margin, margin, margin);
}

FlowLayout::FlowLayout(int margin, int hSpacing, int vSpacing)
    : m_hSpace(hSpacing), m_vSpace(vSpacing)
{
    setContentsMargins(margin, margin, margin, margin);
}

FlowLayout::~FlowLayout()
{
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}

void FlowLayout::addItem(QLayoutItem *item)
{
    itemList.append(item);
}

int FlowLayout::horizontalSpacing() const
{
    return (m_hSpace >= 0) ? m_hSpace : smartSpacing(QStyle::PM_LayoutHorizontalSpacing);
}

int FlowLayout::verticalSpacing() const
{
    return (m_vSpace >= 0) ? m_vSpace : smartSpacing(QStyle::PM_LayoutVerticalSpacing);
}

int FlowLayout::count() const
{
    return itemList.size();
}

QLayoutItem *FlowLayout::itemAt(int index) const
{
    return itemList.value(index);
}

QLayoutItem *FlowLayout::takeAt(int index)
{
    return (index >= 0 && index < itemList.size()) ? itemList.takeAt(index) : nullptr;
}

Qt::Orientations FlowLayout::expandingDirections() const
{
    return Qt::Orientations();
}

bool FlowLayout::hasHeightForWidth() const
{
    return true;
}

int FlowLayout::heightForWidth(int width) const
{
    return doLayout(QRect(0, 0, width, 0), true);
}

QSize FlowLayout::sizeHint() const
{
    return minimumSize();
}

QSize FlowLayout::minimumSize() const
{
    QSize size;
    for (QLayoutItem *item : itemList)
        size = size.expandedTo(item->minimumSize());

    const QMargins margins = contentsMargins();
    size += QSize(margins.left() + margins.right(), margins.top() + margins.bottom());
    return size;
}

void FlowLayout::setGeometry(const QRect &rect)
{
    QLayout::setGeometry(rect);
    doLayout(rect, false);
}

int FlowLayout::doLayout(const QRect &rect, bool testOnly) const
{
    int left, top, right, bottom;
    getContentsMargins(&left, &top, &right, &bottom);

    QRect effectiveRect = rect.adjusted(left, top, -right, -bottom);
    int x = effectiveRect.x();
    int y = effectiveRect.y();
    int lineHeight = 0;

    int spaceX = horizontalSpacing();
    int spaceY = verticalSpacing();

    for (QLayoutItem *item : itemList) {
        QWidget *wid = item->widget();
        if (!wid)
            continue;

        QSize itemSize = item->sizeHint();
        int nextX = x + itemSize.width() + spaceX;

        if (nextX - spaceX > effectiveRect.right() && lineHeight > 0) {
            x = effectiveRect.x();
            y += lineHeight + spaceY;
            nextX = x + itemSize.width() + spaceX;
            lineHeight = 0;
        }

        if (!testOnly) {
            item->setGeometry(QRect(QPoint(x, y), itemSize));
        }

        x = nextX;
        lineHeight = qMax(lineHeight, itemSize.height());
    }

    return y + lineHeight - rect.y() + bottom;
}

int FlowLayout::smartSpacing(QStyle::PixelMetric pm) const
{
    QObject *parentObj = parent();
    if (!parentObj) {
        return -1;
    } else if (parentObj->isWidgetType()) {
        QWidget *pw = static_cast<QWidget *>(parentObj);
        return pw->style()->pixelMetric(pm, nullptr, pw);
    } else {
        return static_cast<QLayout *>(parentObj)->spacing();
    }
}
