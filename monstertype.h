#pragma once
#include <QString>
#include <QList>

struct Attributes {
    int STR = 10;
    int DEX = 10;
    int CON = 10;
    int INT = 10;
    int WIS = 10;
    int CHA = 10;
};

struct Action {
    QString name;
    int toHitModifier;
    QString damageDice;
    QString damageType;
};

class MonsterType {
public:
    virtual QString name() const = 0;
    virtual int baseAC() const = 0;
    virtual QString hpDice() const = 0;
    virtual int speed() const = 0;
    virtual int burrow() const = 0;
    virtual int climb() const = 0;
    virtual int fly() const = 0;
    virtual int swim() const = 0;
    virtual Attributes attributes() const = 0;
    virtual QString saving_throws() const = 0;
    virtual QString skills() const = 0;
    virtual QString vulnerabilities() const = 0;
    virtual QString resistances() const = 0;
    virtual QString immunities() const = 0;
    virtual QString senses() const = 0;
    virtual QString languages() const = 0;
    virtual QList<Action> actions() const = 0;

    virtual ~MonsterType() = default;
};

/*
class  : public MonsterType {
public:
    QString name() const override { return "";}
    int baseAC() const override { return ;}
    QString hpDice() const override { return "";}
    int speed() const override { return ;}
    int burrow() const override { return ;}
    int climb() const override { return ;}
    int fly() const override { return ;}
    int swim() const override { return ;}
    Attributes attributes() const override {
        return Attributes{ , , , , , }; //str, dex, con, int, wis, cha
    }
    QString saving_throws() const override { return "";}
    QString skills() const override { return "";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return ", p.P. ";}
    QString languages() const override { return "";}
    QList<MonsterAction> actions() const override {
        return {
            {"", +, "", ""},
            {"", +, "", ""}
        };
    }
};*/

class Goblin : public MonsterType {
public:
    QString name() const override { return "Goblin";}
    int baseAC() const override { return 15;}
    QString hpDice() const override { return "2d6";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override {
        return Attributes{ 8, 14, 10, 10, 8, 8};//str, dex, con, int, wis, cha
    }
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Stealth +6";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft, p.P. 9";}
    QString languages() const override { return "Common, Goblin";}
    QList<Action> actions() const override {
        return {
            {"Scimitar", +4, "1d6 +2", "slashing"},
            {"Shortbow", +4, "1d6 +2", "piercing"}
        };
    }
};

class GoblinBoss: public MonsterType {
public:
    QString name() const override { return "Goblin Boss";}
    int baseAC() const override { return 17;}
    QString hpDice() const override { return "6d6";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override {
        return Attributes{ 10, 14, 10, 10, 8, 10}; //str, dex, con, int, wis, cha
    }
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Stealth +6";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft, p.P. 9";}
    QString languages() const override { return "Common, Goblin";}
    QList<Action> actions() const override {
        return {
            {"Scimitar", +4, "1d6 +2", "slashing"},
            {"Javelin", +2, "1d6", "piercing"}
        };
    }
};

class Orc : public MonsterType {
public:
    QString name() const override { return "Orc";}
    int baseAC() const override { return 13;}
    QString hpDice() const override { return "2d8 + 6";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override {
        return Attributes{16, 12, 16, 7, 11, 10};//str, dex, con, int, wis, cha
    }
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Intimidation +2";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft, p.P. 10";}
    QString languages() const override { return "Common, Orc";}
    QList<Action> actions() const override {
        return {
            {"Greataxe", +5, "1d12 +3", "slashing"},
            {"Javelin", +5, "1d6 +3", "piercing"}
        };
    }
};


