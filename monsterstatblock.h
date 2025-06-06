#pragma once
#include <QWidget>
#include "MonsterType.h"
#include "monsteraction.h"
#include <cmath>
#include <QLabel>
#include <QVBoxLayout>

class QLabel;
class QVBoxLayout;

class MonsterStatBlock : public QWidget {
    Q_OBJECT

public:
    explicit MonsterStatBlock(const MonsterType& type, QWidget *parent = nullptr);

    void setActions(const QList<MonsterAction> &actions);

private:
    QVBoxLayout *mainLayout;
    QLabel *actionsLabel;

    inline int abilityModifier(int score) {
        return std::floor((score - 10) / 2.0);
    }

    inline QString formatAttribute(int score) {
        int mod = abilityModifier(score);
        QString modStr = (mod >= 0) ? QString("+%1").arg(mod) : QString::number(mod);
        return QString("%1 (%2)").arg(score).arg(modStr);
    }
};
