#pragma once
#include <QString>
#include <QList>
#include "monsteraction.h"

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
    virtual QList<MonsterAction> actions() const = 0;


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
    QList<MonsterAction> actions() const override {
        return {
            {"Scimitar", +4, "1d6", +2, "slashing"},
            {"Shortbow", +4, "1d6", +2, "piercing"}
        };
    }
};

class Orc : public MonsterType {
public:
    QString name() const override { return "Orc"; }
    QString hpDice() const override { return "2d8 + 6"; }
    int baseAC() const override { return 13; }
    Attributes attributes() const override {
        return Attributes{16, 12, 16, 7, 11, 10};
    }
    QList<MonsterAction> actions() const override {
        return {
            {"Greataxe", +5, "1d12", +3, "slashing"},
            {"Javelin", +5, "1d6", +3, "piercing"}
        };
    }
};
