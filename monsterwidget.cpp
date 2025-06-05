#include "MonsterWidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QProgressBar>
#include <QGroupBox>

MonsterWidget::MonsterWidget(const MonsterInstance& instance, QWidget *parent)
    : QWidget(parent) {

    QGroupBox *group = new QGroupBox(instance.name, this);
    QVBoxLayout *layout = new QVBoxLayout();

    acLabel = new QLabel(QString("AC: %1").arg(instance.ac), this);
    hpLabel = new QLabel(QString("HP: %1 / %2").arg(instance.hp).arg(instance.maxHp), this);
    hpBar = new QProgressBar(this);
    hpBar->setRange(0, instance.maxHp);
    hpBar->setValue(instance.hp);

    layout->addWidget(acLabel);
    layout->addWidget(hpLabel);
    layout->addWidget(hpBar);

    group->setLayout(layout);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(group);
    setLayout(mainLayout);
}
