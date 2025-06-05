#pragma once
#include <QString>

class MonsterType {
public:
    virtual QString name() const = 0;
    virtual QString hpDice() const = 0; // e.g., "2d8"
    virtual int baseAC() const = 0;
    virtual ~MonsterType() = default;
};
