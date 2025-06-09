#include "MonsterStatBlock.h"
#include <QVBoxLayout>
#include <QLabel>

MonsterStatBlock::MonsterStatBlock(const MonsterType& type, QWidget *parent)
    : QWidget(parent) {
    auto *layout = new QVBoxLayout(this);
    setWindowTitle(type.name() + " Stat Block");
    setMinimumSize(250, 230);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::Window);

    QWidget *topWidget = new QWidget(this);
    QGridLayout *topLayout = new QGridLayout(topWidget);

    topLayout->addWidget(new QLabel("<b>Name:</b> " + type.name()), 0, 0);
    topLayout->addWidget(new QLabel(QString("<b>AC:</b> %1 ±1").arg(type.baseAC())), 0, 1);
    topLayout->addWidget(new QLabel(QString("<b>HP:</b> %1").arg(type.hpDice())), 0, 2);
    topLayout->addWidget(new QLabel(QString("<b>Speed:</b> %1").arg(type.speed())), 1, 0);
    topLayout->addWidget(new QLabel(QString("<b>Climb:</b> %1").arg(type.climb())), 1, 1);
    topLayout->addWidget(new QLabel(QString("<b>Fly:</b> %1").arg(type.fly())), 1, 2);
    layout->addWidget(topWidget);

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

    layout->addWidget(new QLabel("<b>Attributes:</b>"));
    layout->addLayout(attrLayout);

    layout->addSpacing(5);
    layout->addWidget(new QLabel("<b>Skills:</b> " + type.skills()));
    layout->addWidget(new QLabel("<b>Resistances:</b> " + type.resistances()));
    layout->addWidget(new QLabel("<b>Immunities:</b> " + type.immunities()));

    actionsLabel = new QLabel(this);
    actionsLabel->setTextFormat(Qt::RichText);
    layout->addSpacing(5);
    layout->addWidget(new QLabel("<b>Actions:</b>"));
    layout->addWidget(actionsLabel);

    setActions(type.actions());

    layout->addStretch();
}

void MonsterStatBlock::setActions(const QList<MonsterAction> &actions) {
    QStringList actionStrings;
    for (const MonsterAction &action : actions) {
        QString toHitStr = (action.toHitModifier >= 0) ? QString("+%1").arg(action.toHitModifier) : QString::number(action.toHitModifier);
        QString damageModStr = (action.damageModifier >= 0) ? QString("+%1").arg(action.damageModifier) : QString::number(action.damageModifier);

        QString actionText = QString("%1 %2 to hit, %3 %4 %5")
                                 .arg(action.name)
                                 .arg(toHitStr)
                                 .arg(action.damageDice)
                                 .arg(damageModStr)
                                 .arg(action.damageType);

        actionStrings << actionText;
    }

    actionsLabel->setText(actionStrings.join("<br>"));
}
