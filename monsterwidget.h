#pragma once

#include <QWidget>
#include <QProgressBar>
#include <QLabel>
#include "MonsterInstance.h"
#include <QPushButton>

class MonsterWidget : public QWidget {
    Q_OBJECT

public:
    MonsterWidget(const MonsterInstance& instance, QWidget *parent = nullptr);

signals:
    void monsterDied(MonsterWidget *self);

private slots:
    void takeDamage();
    void heal();

private:
    void updateDisplay();

    QLabel *nameLabel;
    QLabel *acLabel;
    QLabel *hpLabel;
    QProgressBar *hpBar;
    QPushButton *damageButton;
    QPushButton *healButton;

    int hp;
    int maxHp;

};
