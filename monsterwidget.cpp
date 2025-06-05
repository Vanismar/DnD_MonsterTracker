#include "MonsterWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QGroupBox>
#include <QInputDialog>
#include <QMessageBox>


MonsterWidget::MonsterWidget(const MonsterInstance& instance, QWidget *parent)
    : QWidget(parent), hp(instance.hp), maxHp(instance.maxHp) {

    QGroupBox *group = new QGroupBox(instance.name, this);
    QVBoxLayout *vLayout = new QVBoxLayout();

    acLabel = new QLabel(QString("AC: %1").arg(instance.ac), this);
    hpLabel = new QLabel(QString("HP: %1 / %2").arg(instance.hp).arg(instance.maxHp), this);
    hpBar = new QProgressBar(this);
    hpBar->setRange(0, instance.maxHp);
    hpBar->setValue(instance.hp);

    damageButton = new QPushButton("Damage", this);
    healButton = new QPushButton("Heal", this);

    connect(damageButton, &QPushButton::clicked, this, &MonsterWidget::takeDamage);
    connect(healButton, &QPushButton::clicked, this, &MonsterWidget::heal);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(damageButton);
    buttonLayout->addWidget(healButton);

    vLayout->addWidget(acLabel);
    vLayout->addWidget(hpLabel);
    vLayout->addWidget(hpBar);
    vLayout->addLayout(buttonLayout);

    group->setLayout(vLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(group);
    setLayout(mainLayout);

    updateDisplay();
    setMaximumSize(200, 160);
}

void MonsterWidget::updateDisplay() {
    hp = std::clamp(hp, 0, maxHp);
    hpLabel->setText(QString("HP: %1 / %2").arg(hp).arg(maxHp));
    hpBar->setValue(hp);
}

void MonsterWidget::takeDamage() {
    bool ok;
    int amount = QInputDialog::getInt(this, "Damage", "Enter damage amount:", 1, 1, 999, 1, &ok);
    if (!ok) return;

    hp -= amount;
    updateDisplay();

    if (hp <= 0) {
        emit monsterDied(this); // Notify MainWindow to remove
    }
}

void MonsterWidget::heal() {
    bool ok;
    int amount = QInputDialog::getInt(this, "Heal", "Enter healing amount:", 1, 1, 999, 1, &ok);
    if (!ok) return;

    hp += amount;
    updateDisplay();
}
