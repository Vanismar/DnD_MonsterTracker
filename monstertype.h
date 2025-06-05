#pragma once
#include <QString>

class MonsterType {
public:
    virtual QString name() const = 0;
    virtual QString hpDice() const = 0; // e.g., "2d8"
    virtual int baseAC() const = 0;
    virtual ~MonsterType() = default;
};

class Goblin : public MonsterType {
public:
    QString name() const override { return "Goblin"; }
    QString hpDice() const override { return "2d6"; }
    int baseAC() const override { return 13; }
};

class Dragon : public MonsterType {
public:
    QString name() const override { return "Dragon"; }
    QString hpDice() const override { return "10d10"; }
    int baseAC() const override { return 18; }
};

class Orc : public MonsterType {
public:
    QString name() const override { return "Orc"; }
    QString hpDice() const override { return "2d8"; }
    int baseAC() const override { return 12; }
};
