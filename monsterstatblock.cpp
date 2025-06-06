#include "MonsterStatBlock.h"
#include <QVBoxLayout>
#include <QLabel>

MonsterStatBlock::MonsterStatBlock(const MonsterType& type, QWidget *parent)
    : QWidget(parent) {
    setWindowTitle(type.name() + " Stat Block");
    setMinimumSize(250, 150);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::Window);

    auto *layout = new QVBoxLayout(this);

    layout->addWidget(new QLabel("<b>Name:</b> " + type.name()));
    layout->addWidget(new QLabel(QString("<b>HP:</b> %1").arg(type.hpDice())));
    layout->addWidget(new QLabel(QString("<b>AC:</b> %1 ±1").arg(type.baseAC())));
    Attributes attr = type.attributes();

    QGridLayout *attrLayout = new QGridLayout();
    attrLayout->addWidget(new QLabel("<b>STR</b>"), 0, 0);
    attrLayout->addWidget(new QLabel(formatAttribute(attr.STR)), 0, 1);

    attrLayout->addWidget(new QLabel("<b>DEX</b>"), 0, 2);
    attrLayout->addWidget(new QLabel(formatAttribute(attr.DEX)), 0, 3);

    attrLayout->addWidget(new QLabel("<b>CON</b>"), 0, 4);
    attrLayout->addWidget(new QLabel(formatAttribute(attr.CON)), 0, 5);

    attrLayout->addWidget(new QLabel("<b>INT</b>"), 1, 0);
    attrLayout->addWidget(new QLabel(formatAttribute(attr.INT)), 1, 1);

    attrLayout->addWidget(new QLabel("<b>WIS</b>"), 1, 2);
    attrLayout->addWidget(new QLabel(formatAttribute(attr.WIS)), 1, 3);

    attrLayout->addWidget(new QLabel("<b>CHA</b>"), 1, 4);
    attrLayout->addWidget(new QLabel(formatAttribute(attr.CHA)), 1, 5);

    layout->addSpacing(10);
    layout->addWidget(new QLabel("<b>Attributes:</b>"));
    layout->addLayout(attrLayout);

    layout->addStretch();
}
