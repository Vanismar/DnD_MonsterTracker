#pragma once
#include "MonsterType.h"

class Dragon : public MonsterType {
public:
    QString name() const override { return "Dragon"; }
    QString hpDice() const override { return "10d10"; }
    int baseAC() const override { return 18; }
};
