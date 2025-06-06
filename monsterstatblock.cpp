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

    layout->addStretch();
}
