#pragma once
#include <QString>

struct Attributes {
    int STR = 10;
    int DEX = 10;
    int CON = 10;
    int INT = 10;
    int WIS = 10;
    int CHA = 10;
};

class MonsterType {
public:
    virtual QString name() const = 0;
    virtual QString hpDice() const = 0;
    virtual int baseAC() const = 0;
    virtual Attributes attributes() const = 0;

    virtual ~MonsterType() = default;
};

class Goblin : public MonsterType {
public:
    QString name() const override { return "Goblin"; }
    QString hpDice() const override { return "2d6"; }
    int baseAC() const override { return 15; }
    Attributes attributes() const override {
        return Attributes{ 8, 14, 10, 10, 8, 8 };
    }
};

class Dragon : public MonsterType {
public:
    QString name() const override { return "Dragon"; }
    QString hpDice() const override { return "10d10"; }
    int baseAC() const override { return 18; }
    Attributes attributes() const override {
        return Attributes{27, 10, 25, 16, 13, 21};
    }
};

class Orc : public MonsterType {
public:
    QString name() const override { return "Orc"; }
    QString hpDice() const override { return "2d8"; }
    int baseAC() const override { return 12; }
    Attributes attributes() const override {
        return Attributes{16, 12, 16, 7, 11, 10};
    }
};
