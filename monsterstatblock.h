#pragma once
#include <QWidget>
#include "MonsterType.h"

class QLabel;
class QVBoxLayout;

class MonsterStatBlock : public QWidget {
    Q_OBJECT

public:
    explicit MonsterStatBlock(const MonsterType& type, QWidget *parent = nullptr);

    inline int abilityModifier(int score) {
        return (score - 10) / 2; // Integer division rounds down
    }

    inline QString formatAttribute(int score) {
        int mod = abilityModifier(score);
        QString modStr = (mod >= 0) ? QString("+%1").arg(mod) : QString::number(mod);
        return QString("%1 (%2)").arg(score).arg(modStr);
    }
};
