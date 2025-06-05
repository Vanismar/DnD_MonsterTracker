#pragma once

#include <QWidget>
#include <QProgressBar>
#include <QLabel>
#include "MonsterInstance.h"

class MonsterWidget : public QWidget {
    Q_OBJECT

public:
    MonsterWidget(const MonsterInstance& instance, QWidget *parent = nullptr);

private:
    QLabel *nameLabel;
    QLabel *acLabel;
    QLabel *hpLabel;
    QProgressBar *hpBar;
};
