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
    QString toHit;
    QString damageDice;
    QString damageType;
};

struct Trait {
    QString name;
    QString detail;
};

struct Reaction {
    QString name;
    QString detail;
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
    virtual QList<Trait> traits() const = 0;
    virtual QList<Action> actions() const = 0;
    virtual QList<Reaction> reactions() const = 0;

    virtual ~MonsterType() = default;
};

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
    Attributes attributes() const override { return Attributes{ 8, 14, 10, 10, 8, 8};}//str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Stealth +6";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft, p.P. 9";}
    QString languages() const override { return "Common, Goblin";}
    QList<Trait> traits() const override { return {
        {"Nible Escape", "Can take Disengage or Hide as a bonus action"}
    };}
    QList<Action> actions() const override { return {
        {"Scimitar", "+4 to hit,", "1d6 +2", "slashing"},
        {"Shortbow", "+4 to hit,", "1d6 +2", "piercing"}
    };}
    QList<Reaction> reactions() const override { return {
    };}
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
    Attributes attributes() const override { return Attributes{ 10, 14, 10, 10, 8, 10};}//str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Stealth +6";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft, p.P. 9";}
    QString languages() const override { return "Common, Goblin";}
    QList<Trait> traits() const override { return {
        {"Nible Escape", "Can take Disengage or Hide as a bonus action"},
        {"Multiattack", "Makes two attacks with Scimitar. Second attack has disadvantage"}
    };}
    QList<Action> actions() const override { return {
        {"Scimitar", "+4 to hit,", "1d6 +2", "slashing"},
        {"Javelin", "+2 to hit,", "1d6", "piercing"}
    };}
    QList<Reaction> reactions() const override { return {
    };}
};

class Orc : public MonsterType {
public:
    QString name() const override { return "Orc";}
    int baseAC() const override { return 13;}
    QString hpDice() const override { return "2d8 +6";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{16, 12, 16, 7, 11, 10};}//str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Intimidation +2";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft, p.P. 10";}
    QString languages() const override { return "Common, Orc";}
    QList<Trait> traits() const override { return {
        {"Aggressive", "As a bonus action, can move up to its speed toward a hostile"}
    };}
    QList<Action> actions() const override { return {
        {"Greataxe", "+5 to hit,", "1d12 +3", "slashing"},
        {"Javelin", "+5 to hit,", "1d6 +3", "piercing"}
    };}
    QList<Reaction> reactions() const override { return {
    };}
};

class Spectator : public MonsterType {
public:
    QString name() const override { return "Spectator";}
    int baseAC() const override { return 14;}
    QString hpDice() const override { return "6d8 +12";}
    int speed() const override { return 0;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 30;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 8, 14, 14, 13, 14, 11};}//str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Perception +6";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "prone";}
    QString senses() const override { return "darkvision 120ft., p.P. 16";}
    QString languages() const override { return "Deep Speech, Undercommon, telepathy 120 ft.";}
    QList<Trait> traits() const override { return {
    };}
    QList<Action> actions() const override {return {
        {"Bite", "+1 to hit,", "1d6 -1", "piercing"},
        {"Eye Rays", "shoot up to two eye rays at one or two creatures it can see within 90ft.", "Each ray can be used only once a turn", ""},
        {"Confusion Ray", "DC 13 Wis,", "on fail it can't take reactions until end of its next turn", "target can't move and attacks a random target in range"},
        {"Paralyzing Ray", "DC 13 Con,", "on fail become paralyzed for 1min.", "The target can repeat the saving throw at the end of it's turns"},
        {"Fear Ray", "DC 13 Wis,", "on fail become frightened for 1min.", "The target can repeat the saving throw at the end of it's turns, with disadvantage if the spectator is visible"},
        {"Wounding Ray", "DC 13 Con,", "on fail take 3d10 necrotic damage.", "On success take half damage"},
        {"Create Food and Water", "creates enough food and water to sustain itself for 24 hours", "", ""}
    };}
    QList<Reaction> reactions() const override { return {
        {"Spell reflection", "if saved against a spell, or the spell misses.The spectator can redirect it at another creature within 30ft."}
    };}
};

class TwigBlight : public MonsterType {
public:
    QString name() const override { return "Twig Blight";}
    int baseAC() const override { return 13;}
    QString hpDice() const override { return "1d6 +1";}
    int speed() const override { return 20;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override {return Attributes{ 6, 13, 12, 4, 8, 3};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Stealth +3";}
    QString vulnerabilities() const override { return "fire";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "Blinded, deafened";}
    QString senses() const override { return "blindsight 60ft., p.P. 9";}
    QString languages() const override { return "Common(only understands)";}
    QList<Trait> traits() const override { return {
        {"False Appearance", "While motionless, it is indistinguishable from a dead shrub"}
    };}
    QList<Action> actions() const override { return {
        {"Claws", "+3 to hit", "1d4 +1", "piercing"}
    };}
    QList<Reaction> reactions() const override { return {
    };}
};

class Bugbear : public MonsterType {
public:
    QString name() const override { return "Bugbear";}
    int baseAC() const override { return 16;}
    QString hpDice() const override { return "5d8 +5";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 15, 14, 13, 8, 11, 9};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Stealth +6, Survival +2";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft., p.P. 10";}
    QString languages() const override { return "Common, Goblin";}
    QList<Trait> traits() const override { return {
        {"Brute", "attacks do one extra die of its damage(included in attack)"},
        {"Surprise Attack", "if the bugbear surprises a creature and attacks it in the first round, target takes extra 2d6 damage"}
    };}
    QList<Action> actions() const override { return {
        {"Morningstar", "+4 to hit", "2d8 +2", "piercing"},
        {"Javelin", "+4 to hit", "2d6 +2", "piercing"}
    };}
    QList<Reaction> reactions() const override { return {
    };}
};

class BugbearChief : public MonsterType {
public:
    QString name() const override { return "Bugbear Chief";}
    int baseAC() const override { return 17;}
    QString hpDice() const override { return "10d8 +20";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 17, 14, 14, 11, 12, 11};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Intimidation +2, Stealth +6, Survival +3";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return ",darkvision 60ft. p.P. 11";}
    QString languages() const override { return "Common, Goblin";}
    QList<Trait> traits() const override { return {
        {"Brute", "attacks do one extra die of its damage(included in attack)"},
        {"Surprise Attack", "if the bugbear surprises a creature and attacks it in the first round, target takes extra 2d6 damage"},
        {"Heart of Hruggek", "has advantage on saving throws against being charmed, frightened, paralyzed, poisoned, stunned or put to sleep"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "make two melee attacks", "", ""},
        {"Morningstar", "+5 to hit", "2d8 +3", "piercing"},
        {"Javelin", "+5 to hit", "2d6 +3", "piercing"}
    };}
    QList<Reaction> reactions() const override { return {
    };}
};

class Doppelganger : public MonsterType {
public:
    QString name() const override { return "Doppelganger";}
    int baseAC() const override { return 14;}
    QString hpDice() const override { return "8d8 +16";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 11, 18, 14, 11, 12, 14};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Deception +6, Insight +3";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "charmed";}
    QString senses() const override { return "darkvision 60ft., p.P. 11";}
    QString languages() const override { return "Common";}
    QList<Trait> traits() const override { return {
        {"Shapechanger", "as an action polymorph into a small or medium humanoid it has seen"},
        {"Ambusher", "in the first round of combat have advantage on attack rolls"},
        {"Surprise Attack", "if the doppelganger surprises a creature and attacks it in the first round, target takes extra 3d6 damage"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "make two melee attacks", "", ""},
        {"Slam", "+6 to hit", "1d6 +4", "bludgeoning"},
        {"Read Thoughts", "can read surface thoughts  of one creature within 60ft.", "Can be blocket by 3ft. wood, 2ft. stone, 2in. metal or sheet of lead.", "While reading thought have advantage on insight, deception, intimidation and persuasion"}
    };}
    QList<Reaction> reactions() const override { return {
    };}
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
    Attributes attributes() const override { return Attributes{ , , , , , };} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return ", p.P. ";}
    QString languages() const override { return "";}
    QList<Trait> traits() const override { return {
        {"", ""},
        {"", ""}
    };}
    QList<Action> actions() const override { return {
        {"", " to hit", "", ""},
        {"", " to hit", "", ""}
    };}
    QList<Reaction> reactions() const override { return {
        {"", ""},
        {"", ""}
    };}
};*/
