#pragma once
#include "MonsterType.h"

class Goblin : public MonsterType {
public:
    QString name() const override { return "Goblin"; }
    QString hpDice() const override { return "2d6"; }
    int baseAC() const override { return 13; }
};
