#pragma once
#include "MonsterType.h"

class Orc : public MonsterType {
public:
    QString name() const override { return "Orc"; }
    QString hpDice() const override { return "2d8"; }
    int baseAC() const override { return 12; }
};
