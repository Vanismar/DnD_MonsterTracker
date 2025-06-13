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
    virtual QList<Action> traits() const = 0;
    virtual QList<Action> actions() const = 0;
    virtual QList<Action> reactions() const = 0;
    virtual QList<Action> legendaries() const = 0;

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
    QList<Action> traits() const override { return {
        {"Nible Escape", "Can take Disengage or Hide as a bonus action"}
    };}
    QList<Action> actions() const override { return {
        {"Scimitar", "+4 to hit, 1d6 +2 slashing"},
        {"Shortbow", "+4 to hit, range 80/320ft., 1d6 +2 piercing"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
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
    QList<Action> traits() const override { return {
        {"Nible Escape", "Can take Disengage or Hide as a bonus action"},
        {"Multiattack", "Makes two attacks with Scimitar. Second attack has disadvantage"}
    };}
    QList<Action> actions() const override { return {
        {"Scimitar", "+4 to hit, 1d6 +2 slashing"},
        {"Javelin", "+2 to hit, range 30/120ft., 1d6 piercing"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
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
    QList<Action> traits() const override { return {
        {"Aggressive", "As a bonus action, can move up to its speed toward a hostile"}
    };}
    QList<Action> actions() const override { return {
        {"Greataxe", "+5 to hit, 1d12 +3 slashing"},
        {"Javelin", "+5 to hit, range 30/120ft., 1d6 +3 piercing"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
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
    QList<Action> traits() const override { return {
    };}
    QList<Action> actions() const override {return {
        {"Bite", "+1 to hit, 1d6 -1 piercing"},
        {"Eye Rays", "Shoot up to two eye rays at one or two creatures it can see within 90ft., each ray can be used only once a turn"},
        {"Confusion Ray", "DC 13 Wis, on fail it can't take reactions until end of its next turn, target can't move and attacks a random target in range"},
        {"Paralyzing Ray", "DC 13 Con, on fail become paralyzed for 1min. The target can repeat the saving throw at the end of its turns"},
        {"Fear Ray", "DC 13 Wis, on fail become frightened for 1min. The target can repeat the saving throw at the end of it's turns, with disadvantage if the spectator is visible"},
        {"Wounding Ray", "DC 13 Con, on fail take 3d10 necrotic damage. On success take half damage"},
        {"Create Food and Water", "Creates enough food and water to sustain itself for 24 hours"}
    };}
    QList<Action> reactions() const override { return {
        {"Spell reflection", "If saved against a spell, or the spell misses. The spectator can redirect it at another creature within 30ft."}
    };}
    QList<Action> legendaries() const override { return {
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
    QList<Action> traits() const override { return {
        {"False Appearance", "While motionless, it is indistinguishable from a dead shrub"}
    };}
    QList<Action> actions() const override { return {
        {"Claws", "+3 to hit, 1d4 +1 piercing"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
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
    QList<Action> traits() const override { return {
        {"Brute", "Attacks do one extra die of its damage(included in attack)"},
        {"Surprise Attack", "If the bugbear surprises a creature and attacks it in the first round, target takes extra 2d6 damage"}
    };}
    QList<Action> actions() const override { return {
        {"Morningstar", "+4 to hit, 2d8 +2 piercing"},
        {"Javelin", "+4 to hit, range 30/120ft., 2d6 +2 piercing in melee or 1d6 +2 piercing at range"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
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
    QList<Action> traits() const override { return {
        {"Brute", "Attacks do one extra die of its damage(included in attack)"},
        {"Surprise Attack", "If the bugbear surprises a creature and attacks it in the first round, target takes extra 2d6 damage"},
        {"Heart of Hruggek", "Has advantage on saving throws against being charmed, frightened, paralyzed, poisoned, stunned or put to sleep"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make two melee attacks"},
        {"Morningstar", "+5 to hit, 2d8 +3 piercing"},
        {"Javelin", "+5 to hit, range 30/120ft., 2d6 +3 piercing in melee or 1d6 +3 piercing at range"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
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
    QList<Action> traits() const override { return {
        {"Shapechanger", "As an action polymorph into a small or medium humanoid it has seen"},
        {"Ambusher", "In the first round of combat have advantage on attack rolls"},
        {"Surprise Attack", "If the doppelganger surprises a creature and attacks it in the first round, target takes extra 3d6 damage"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make two melee attacks"},
        {"Slam", "+6 to hit, 1d6 +4 bludgeoning"},
        {"Read Thoughts", "Can read surface thoughts of one creature within 60ft., Can be blocket by 3ft. wood, 2ft. stone, 2in. metal or sheet of lead. While reading thought have advantage on insight, deception, intimidation and persuasion"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class Grick : public MonsterType {
public:
    QString name() const override { return "Grick";}
    int baseAC() const override { return 14;}
    QString hpDice() const override { return "6d8";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 30;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 14, 14, 11, 3, 14, 5};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "bludgeoning, piercing and slashing from nonmagical attacks";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft., p.P. 12";}
    QString languages() const override { return "";}
    QList<Action> traits() const override { return {
        {"Stone Camouflage", "Has advantage on Stealth checks in rocky terain"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make one attack with tentacles, if the attack hits make one with beak on same target"},
        {"Tentacles", "+4 to hit, 2d6 +2 slashing"},
        {"Beak", "+4 to hit, 1d6 +2 piercing"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class GrickAlpha : public MonsterType {
public:
    QString name() const override { return "Grick Alpha";}
    int baseAC() const override { return 18;}
    QString hpDice() const override { return "10d10 +20";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 30;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 18, 16, 15, 4, 14, 9};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "bludgeoning, piercing and slashing from nonmagical attacks";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft., p.P. 12";}
    QString languages() const override { return "";}
    QList<Action> traits() const override { return {
        {"Stone Camouflage", "Has advantage on Stealth checks in rocky terain"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make two attacks: one with tail and one with tentacles, if tentacles hit make one with beak on same target"},
        {"Tail", "+7 to hit, 2d6 +4 bludgeoning"},
        {"Tentacles", "+7 to hit, 4d8 +4 slashing"},
        {"Beak", "+7 to hit, 2d8 +4 piercing"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class Hobgoblin : public MonsterType {
public:
    QString name() const override { return "Hobgoblin";}
    int baseAC() const override { return 18;}
    QString hpDice() const override { return "2d8 +2";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 13, 12, 12, 10, 10, 9};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft., p.P. 10";}
    QString languages() const override { return "Common, Goblin";}
    QList<Action> traits() const override { return {
        {"Martial Advantage", "Once per turn, can deal extra 2d6 to a creature if there is an ally(functional) within 5ft. of the creature"}
    };}
    QList<Action> actions() const override { return {
        {"Longsword", "+3 to hit, 1d8 +1 slashing or 1d10 +1 slashing, if two-handing"},
        {"Longbow", "+3 to hit, range 150/600ft., 1d8 +1 piercing"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class HobgoblinCaptain : public MonsterType {
public:
    QString name() const override { return "Hobgoblin Captain";}
    int baseAC() const override { return 17;}
    QString hpDice() const override { return "6d8 +12";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 15, 14, 14, 12, 10, 13};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft., p.P. 10";}
    QString languages() const override { return "Common, Goblin";}
    QList<Action> traits() const override { return {
        {"Martial Advantage", "Once per turn, can deal extra 3d6 to a creature if there is an ally(functional) within 5ft. of the creature"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make two greatsword attacks"},
        {"Greatsword", "+4 to hit, 2d6 +2 piercing"},
        {"Javelin", "+4 to hit, range 30/120ft., 1d6 +2 piercing"},
        {"Leadership(once a rest)", "For 1min give a creature +1d4 to its attack rolls and saving throws, untill end or incapacitaion of the leader"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class HobgoblinWarlord : public MonsterType {
public:
    QString name() const override { return "Hobgoblin Warlord";}
    int baseAC() const override { return 20;}
    QString hpDice() const override { return "13d8 +39";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 16, 14, 16, 14, 11, 15};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Int +5, Wis +3, Cha +5";}
    QString skills() const override { return "";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft., p.P. 10";}
    QString languages() const override { return "Common, Goblin";}
    QList<Action> traits() const override { return {
        {"Martial Advantage", "Once per turn, can deal extra 4d6 to a creature if there is an ally(functional) within 5ft. of the creature"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make three melee attacks or two ranged attacks"},
        {"Longsword", "+9 to hit, 1d8 +3 slashing or 1d10 +3 slashing, if two-handing"},
        {"Shield Bash", "+9 to hit, 1d4 +3 bludgeoning. If target is large or smaller it must succeed DC 14 Str save or be knocked prone"},
        {"Javelin", "+9 to hit, range 30/120ft., 1d6 +3 piercing"},
        {"Leadership(once a rest)", "For 1min give a creature +1d4 to its attack rolls and saving throws, untill end or incapacitaion of the leader"}
    };}
    QList<Action> reactions() const override { return {
        {"Parry", "Add 3 to its AC against one melle attack. Must see the attacker and have a melee weapon"}
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class Mimic : public MonsterType {
public:
    QString name() const override { return "Mimic";}
    int baseAC() const override { return 12;}
    QString hpDice() const override { return "9d8 +18";}
    int speed() const override { return 15;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 17, 12, 15, 5, 13, 8};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Stealth +5";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "acid, prone";}
    QString senses() const override { return "darkvision 60ft., p.P. 11";}
    QString languages() const override { return "";}
    QList<Action> traits() const override { return {
        {"Shapechanger", "Can use its action to polymorph into an object"},
        {"Adhesive(Object Form Only)", "Adheres to anything it touches. A Huge or smaller adhered to the mimic is grappled(escape DC 13). Attemps to escape are disadvantaged"},
        {"False Appearance(Object Form Only)", "While motionless, it is indistinguishable from an ordinary object."},
        {"Grappler", "Has advantage on attack rolls against any creature grappled by it"}
    };}
    QList<Action> actions() const override { return {
        {"Pseudopod", "+5 to hit, 1d8 +3 bludgeoning"},
        {"Bite", "+5 to hit, 1d8 +3 piercing and 1d8 acid"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class Nothic : public MonsterType {
public:
    QString name() const override { return "Nothic";}
    int baseAC() const override { return 15;}
    QString hpDice() const override { return "6d8 +18";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 14, 16, 16, 13, 10, 8};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Arcana +3, Insight +4, Perception +2, Stealth +5";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "truesight 120ft, p.P. 12";}
    QString languages() const override { return "Undercommon";}
    QList<Action> traits() const override { return {
        {"Keen Sight", "Has advantage on Perception checks that rely on sight"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make two claw attacks"},
        {"Claw", "+4 to hit, 1d6 +3 slashing"},
        {"Rotting Gaze", "Target one creature it can see within 30ft.. DC 12 Con save, on fail take 3d6 necrotic"},
        {"Weird Insight", "Target one creature it can see within 30ft.. Contest target Deception vs its Insight. If Nothic wins it learns one fact or secret about the target. Target wins if its immune to charmed"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class BlackPudding : public MonsterType {
public:
    QString name() const override { return "Black Pudding";}
    int baseAC() const override { return 7;}
    QString hpDice() const override { return "10d10 +30";}
    int speed() const override { return 20;}
    int burrow() const override { return 0;}
    int climb() const override { return 20;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 16, 5, 16, 1, 6, 1};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "acid, cold, lightning, slashing, blinded, charmed, deafened, exhaustion, frightened, prone";}
    QString senses() const override { return "blindsight 60ft., p.P. 8";}
    QString languages() const override { return "";}
    QList<Action> traits() const override { return {
        {"Amorphous", "Can move through a space as narrow a 1in. wide"},
        {"Corrosive Form", "A creature that touches the pudding or hits while within 5ft. takes 1d8 acid. Any nonmagical weapon corrodes. The corroded weapon takes -1 to its damage roll permanently, if it reaches -5 the weapon is destroyed"},
        {"Spider Climb", "Can climb difficult surfaces, including upside down on ceilings, without making ability check"}
    };}
    QList<Action> actions() const override { return {
        {"Pseudopod", "+5 to hit, 1d6 +3 bludgeoning and 4d8 acid. In addition nonmagical armor is partly dissolved and takes permanent -1 AC. The armor is destroyed if its AC becomes 10"}
    };}
    QList<Action> reactions() const override { return {
        {"Split", "When a pudding Medium or Large is hit with slashing or lightning and has more than 10 hp. It splits into two new puddings each with half the hp"}
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class GelatinousCube : public MonsterType {
public:
    QString name() const override { return "Gelatinous Cube";}
    int baseAC() const override { return 6;}
    QString hpDice() const override { return "8d10 +40";}
    int speed() const override { return 15;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 14, 3, 20, 1, 6, 1};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "blinded, charmed, deafened, exhaustion, frightened, prone";}
    QString senses() const override { return "blindsight 60ft., p.P. 8";}
    QString languages() const override { return "";}
    QList<Action> traits() const override { return {
        {"Ooze Cube", "The cube takes up its entire space. Other creatures can enter the space, but a creature that does so is subjected to the cube's Engulf and has disadvantage on the saving throw. Creatures inside the cube can be seen but have total cover. A creature can take  an action to pull a creature or object out of the cube. Doing so requires a successful DC 12 Strength check, and the creature making the attempt takes 3d6 acid. Can hold only one Large creature or up to four Medium or smaller creatures inside it at a time."},
        {"Transparent", "Even when the cube is in plain sight, it takes a successful DC 15 Perception check to spot a cube that has neither moved nor attacked. A creature that tries to enter the cube's space while unaware of the cube is surprised by the cube."}
    };}
    QList<Action> actions() const override { return {
        {"Pseudopod", "+4 to hit, 3d6 acid"},
        {"Engulf", "The cube moves up to its speed. While doing so, it can enter Large or smaller creatures' spaces. Whenever the cube enters a creature's space, the creature must make a DC 12 Dexterity save. On a successful save, the creature can choose to be pushed 5 feet back or to the side of the cube. A creature that chooses not to be pushed fails the save. On a failed save, the cube enters the creature's space, and the creature takes 3d6 acid and is engulfed. The engulfed creature can't breathe, is restrained, and takes 6d6 acid at the start of each of the cube's turns. When the cube moves, the engulfed creature moves with it. An engulfed creature can escape by succeding DC 12 Strength check."}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class GrayOoze : public MonsterType {
public:
    QString name() const override { return "Gray Ooze";}
    int baseAC() const override { return 8;}
    QString hpDice() const override { return "3d8 +9";}
    int speed() const override { return 10;}
    int burrow() const override { return 0;}
    int climb() const override { return 10;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 12, 6, 16, 1, 6, 2};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Stealth +2";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "acid, cold, fire";}
    QString immunities() const override { return "blinded, charmed, deafened, exhaustion, frightened, prone";}
    QString senses() const override { return "blindsight 60ft., p.P. 8";}
    QString languages() const override { return "";}
    QList<Action> traits() const override { return {
        {"Amorphous", "Can move through a space as narrow a 1in. wide"},
        {"Corrode Metal", "Any nonmagical weapon that hits the ooze is corroded. The corroded weapon takes -1 to its damage roll permanently, if it reaches -5 the weapon is destroyed"},
        {"False Appearance", "While motionless, it is indistinguishable from an oily pool or wet rock"}
    };}
    QList<Action> actions() const override { return {
        {"Pseudopod", "3+ to hit, 1d6 +1 bludgeoning and 2d6 acid. In addition nonmagical armor is partly dissolved and takes permanent -1 AC. The armor is destroyed if its AC becomes 10"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class OchreJelly : public MonsterType {
public:
    QString name() const override { return "Ochre Jelly";}
    int baseAC() const override { return 8;}
    QString hpDice() const override { return "6d10 +12";}
    int speed() const override { return 10;}
    int burrow() const override { return 0;}
    int climb() const override { return 10;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 15, 6, 14, 2, 6, 1};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "acid";}
    QString immunities() const override { return "lightning, slashing, blinded, charmed, deafened, exhaustion, frightened, prone";}
    QString senses() const override { return "blindsight 60ft., p.P. 8";}
    QString languages() const override { return "";}
    QList<Action> traits() const override { return {
        {"Amorphous", "Can move through a space as narrow a 1in. wide"},
        {"Spider Climb", "Can climb difficult surfaces, including upside down on ceilings, without making ability check"}
    };}
    QList<Action> actions() const override { return {
        {"Pseudopod", "+4 to hit, 2d6 +2 bludgeoning and 1d6 acid"},
    };}
    QList<Action> reactions() const override { return {
        {"Split", "When a pudding Medium or Large is hit with slashing or lightning and has more than 10 hp. It splits into two new puddings each with half the hp"}
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class OrcWarChief : public MonsterType {
public:
    QString name() const override { return "Orc War Chief";}
    int baseAC() const override { return 16;}
    QString hpDice() const override { return "11d8 +44";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 18, 12, 18, 11, 11, 16};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Str +6, Con +6, Wis +2";}
    QString skills() const override { return "Intimidation +5";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft., p.P. 10";}
    QString languages() const override { return "Common, Orc";}
    QList<Action> traits() const override { return {
        {"Aggressive", "As a bonus action, can move up to its speed toward a hostile"},
        {"Gruumsh's Fury", "Deal an extra 1d8 with weapon attacks(already included)"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "make two attacks with Greataxe or spear"},
        {"Greataxe", "+6 to hit, 1d12 +4 and 1d8 slashing"},
        {"Spear", "+6 to hit, range 20/60ft., 1d6 +4 and 1d8 piercing or 2d8 +4 piercing, if two-handing "},
        {"Battle Cry(1/day)", "Every ally within 30ft. that can hear the cry gains an advantage on attack rolls until the start of the war chiefs next turn. The war chief can make one attack as a bonus action"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class OrcEyeofGruumsh : public MonsterType {
public:
    QString name() const override { return "Orc Eye of Gruumsh";}
    int baseAC() const override { return 16;}
    QString hpDice() const override { return "6d8 +18";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 16, 12, 16, 9, 13, 12};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Intimidation +3, Religion +1";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft., p.P. 11";}
    QString languages() const override { return "Common, Orc";}
    QList<Action> traits() const override { return {
        {"Aggressive", "As a bonus action, can move up to its speed toward a hostile"},
        {"Gruumsh's Fury", "Deal an extra 1d8 with weapon attacks(already included)"},
        {"Spellcasting", "Wisdom(spell save DC 11, +3 to hit with spells)"},
        {"Cantrips", "guidance, resitance, thaumaturgy"},
        {"1st level(4 slots)", "bless, command"},
        {"2nd level(2 slots)", "augury, spiritual weapon(spear)"}
    };}
    QList<Action> actions() const override { return {
        {"Spear", "+5 to hit, range 20/60ft., 1d6 +3 and 1d8 piercing, or 2d8 +3 piercing, if two-handing"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class Orog : public MonsterType {
public:
    QString name() const override { return "Orog";}
    int baseAC() const override { return 18;}
    QString hpDice() const override { return "5d8 +20";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 18, 12, 18, 12, 11, 12};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Intimidation +5, Survival +2";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft., p.P. 10";}
    QString languages() const override { return "Common, Orc";}
    QList<Action> traits() const override { return {
        {"Aggressive", "As a bonus action, can move up to its speed toward a hostile"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make two greataxe attacks"},
        {"Greataxe", "+6 to hit, 1d12 +4 slashing"},
        {"Javelin", "+6 to hit, range 30/120ft., 1d6 +4 piercing"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class Owlbear : public MonsterType {
public:
    QString name() const override { return "Owlbear";}
    int baseAC() const override { return 13;}
    QString hpDice() const override { return "7d10 +21";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 20, 12, 17, 3, 12, 7};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "Perception +3";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft., p.P. 13";}
    QString languages() const override { return "";}
    QList<Action> traits() const override { return {
        {"Keen Sight and Smell", "has advantage on Perception that rely on sight and smell"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make two attacks: one with beak and one with claw"},
        {"Beak", "+7 to hit, 1d10 +5 piercing"},
        {"Claws", "+7 to hit, 2d8 +5 slashing"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class Skeleton : public MonsterType {
public:
    QString name() const override { return "Skeleton";}
    int baseAC() const override { return 13;}
    QString hpDice() const override { return "2d8 +4";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 10, 14, 15, 6, 8, 5};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "";}
    QString vulnerabilities() const override { return "bludgeoning";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "poison, exhaustion, poisoned";}
    QString senses() const override { return "darkvision 60ft., p.P. 9";}
    QString languages() const override { return "understands languages it spoke in life, but can't speak";}
    QList<Action> traits() const override { return {
    };}
    QList<Action> actions() const override { return {
        {"Shortsword", "+4 to hit, 1d6 +2 piercing"},
        {"Shortbow", "+4 to hit, range 80/320ft., 1d6 +2 piercing"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class MinotaurSkeleton : public MonsterType {
public:
    QString name() const override { return "Minotaur Skeleton";}
    int baseAC() const override { return 12;}
    QString hpDice() const override { return "9d10 +18";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 18, 11, 15, 6, 8, 5};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "";}
    QString vulnerabilities() const override { return "bludgeoning";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "poison, exhaustion, poisoned";}
    QString senses() const override { return "darkvision 60ft., p.P. 9";}
    QString languages() const override { return "understands Abyssal, but can't speak";}
    QList<Action> traits() const override { return {
        {"Charge", "If moves at least 10ft. straight towards a target and hits with gore on the same turn, target takes extra 2d8 piercing. Target makes DC 14 Str save, on fail is pushed up to 10ft. and is knocked prone"}
    };}
    QList<Action> actions() const override { return {
        {"Greataxe", "+6 to hit, 2d12 +4 slashing"},
        {"Gore", "+6 to hit, 2d8 +4 piercing"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class WarhorseSkeleton : public MonsterType {
public:
    QString name() const override { return "Warhorse Skeleton";}
    int baseAC() const override { return 13;}
    QString hpDice() const override { return "3d10 +6";}
    int speed() const override { return 60;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 18, 12, 15, 2, 8, 5};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "";}
    QString vulnerabilities() const override { return "bludgeoning";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "poison, exhaustion, poisoned";}
    QString senses() const override { return "darkvision 60ft., p.P. 9";}
    QString languages() const override { return "";}
    QList<Action> traits() const override { return {
    };}
    QList<Action> actions() const override { return {
        {"Hooves", "+6 to hit, 2d6 +4 bludgeoning"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class AncientBlackDragon : public MonsterType {
public:
    QString name() const override { return "Ancient Black Dragon";}
    int baseAC() const override { return 22;}
    QString hpDice() const override { return "21d20 +147";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 27, 14, 25, 16, 15, 19};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +9, Con +14, Wis +9, Cha +11";}
    QString skills() const override { return "Perception +16, Stealth +9";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "acid";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 26";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"},
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+15 to hit, reach 15ft., 2d10 +8 piercing and 2d8 acid"},
        {"Claw", "+15 to hit, reach 10ft., 2d6 +8 slashing"},
        {"Tail", "+15 to hit, reach 20ft., 2d8 +8 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 19 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Acid Breath(Recharge 5-6)", "90ft. cone 10ft. wide. DC 22 Dex Save, on fail take 15d8 acid or half if sucesfull."}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 23 Dex save or take 2d6 +8 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class AdultBlackDragon : public MonsterType {
public:
    QString name() const override { return "Adult Black Dragon";}
    int baseAC() const override { return 19;}
    QString hpDice() const override { return "17d12 +85";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 23, 14, 21, 14, 13, 17};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +7, Con +10, Wis +6, Cha +8";}
    QString skills() const override { return "Perception +11, Stealth +7";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "acid";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 21";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"},
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+11 to hit, reach 10ft., 2d10 +6 piercing and 1d8 acid"},
        {"Claw", "+11 to hit, reach 5ft., 2d6 +6 slashing"},
        {"Tail", "+11 to hit, reach 15ft., 2d8 +6 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 16 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Acid Breath(Recharge 5-6)", "60ft. line 5ft. wide. DC 18 Dex, on fail take 12d8 acid or half if successful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 19 Dex save or take 2d6 +6 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class YoungBlackDragon : public MonsterType {
public:
    QString name() const override { return "Young Black Dragon";}
    int baseAC() const override { return 18;}
    QString hpDice() const override { return "15d10 +45";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 19, 14, 17, 12, 11, 15};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +5, Con +6, Wis +3, Cha +5";}
    QString skills() const override { return "Perception +6, Stealth +5";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "acid";}
    QString senses() const override { return "blindsight 30ft., darkvision 120ft., p.P. 16";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make three attacks: one with bite and two with claws"},
        {"Bite", "+7 to hit, reach 10ft., 2d10 +4 piercing and 1d8 acid"},
        {"Claw", "+7 to hit, reach 5ft., 2d6 +4 slashing"},
        {"Acid Breath(Recharge 5-6)", "30ft. line 5ft. wide. DC 14 Dex, on fail take 11d8 acid or half if successful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class BlackDragonWyrmling : public MonsterType {
public:
    QString name() const override { return "Black Dragon Wyrmling";}
    int baseAC() const override { return 17;}
    QString hpDice() const override { return "6d8 +6";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 60;}
    int swim() const override { return 30;}
    Attributes attributes() const override { return Attributes{ 15, 14, 13, 10, 11, 13};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +4, Con +3, Wis +2, Cha +3";}
    QString skills() const override { return "Perception +4, Stealth +4";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "acid";}
    QString senses() const override { return "blindsight 10ft., darkvision 60ft., p.P. 14";}
    QString languages() const override { return "Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"}
    };}
    QList<Action> actions() const override { return {
        {"Bite", "+4 to hit, reach 5ft., 1d10 +2 piercing and 1d4 acid"},
        {"Acid Breath(Recharge 5-6)", "15ft. line 5ft. wide. DC 11 Dex, on fail take 5d8 acid or half if successful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class AncientBlueDragon : public MonsterType {
public:
    QString name() const override { return "Ancient Blue Dragon";}
    int baseAC() const override { return 22;}
    QString hpDice() const override { return "26d20 +208";}
    int speed() const override { return 40;}
    int burrow() const override { return 40;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 29, 10, 27, 18, 17, 21};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +7, Con +15, Wis +10, Cha +12";}
    QString skills() const override { return "Perception +17, Stealth +7";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "lightning";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 27";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+16 to hit, reach 15ft., 2d10 +9 piercing and 2d10 lightning"},
        {"Claw", "+16 to hit, reach 10ft., 2d6 +9 slashing"},
        {"Tail", "+16 to hit, reach 20ft., 2d8 +9 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 20 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Lightning Breath(Recharge 5-6)", "120ft. line 10ft. wide. DC 23 Dex Save, on fail take 16d10 lightning or half if sucesfull."}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 24 Dex save or take 2d6 +9 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class AdultBlueDragon : public MonsterType {
public:
    QString name() const override { return "Adult Blue Dragon";}
    int baseAC() const override { return 19;}
    QString hpDice() const override { return "18d12 +108";}
    int speed() const override { return 40;}
    int burrow() const override { return 30;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 25, 10, 23, 16, 15, 19};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +5, Con +11, Wis +7, Cha +9";}
    QString skills() const override { return "Perception +12, Stealth +5";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "lightning";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 22";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+12 to hit, reach 10ft., 2d10 +7 piercing and 1d10 lightning"},
        {"Claw", "+12 to hit, reach 5ft., 2d6 +7 slashing"},
        {"Tail", "+12 to hit, reach 15ft., 2d8 +7 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 17 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Lightning Breath(Recharge 5-6)", "60ft. line 5ft. wide. DC 19 Dex, on fail take 12d10 lightning or half if successful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 20 Dex save or take 2d6 +7 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class YoungBlueDragon : public MonsterType {
public:
    QString name() const override { return "Young Blue Dragon";}
    int baseAC() const override { return 18;}
    QString hpDice() const override { return "16d10 +64";}
    int speed() const override { return 40;}
    int burrow() const override { return 20;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 21, 10, 19, 14, 13, 17};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +4, Con +8, Wis +5, Cha +7";}
    QString skills() const override { return "Perception +9, Stealth +4";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "lightning";}
    QString senses() const override { return "blindsight 30ft., darkvision 120ft., p.P. 19";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make three attacks: one with bite and two with claws"},
        {"Bite", "+9 to hit, reach 10ft., 2d10 +5 piercing and 1d10 lightning"},
        {"Claw", "+9 to hit, reach 5ft., 2d6 +5 slashing"},
        {"Lightning Breath(Recharge 5-6)", "60ft. line 5ft. wide. DC 16 Dex, on fail take 10d10 lightning or half if successful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class BlueDragonWyrmling : public MonsterType {
public:
    QString name() const override { return "Blue Dragon Wyrmling";}
    int baseAC() const override { return 17;}
    QString hpDice() const override { return "8d8 +16";}
    int speed() const override { return 30;}
    int burrow() const override { return 15;}
    int climb() const override { return 0;}
    int fly() const override { return 60;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 17, 10, 15, 12, 11, 15};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +2, Con +4, Wis +2, Cha +4";}
    QString skills() const override { return "Perception +4, Stealth +2";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "lightning";}
    QString senses() const override { return "blindsight 10ft., darkvision 60ft., p.P. 14";}
    QString languages() const override { return "Draconic";}
    QList<Action> traits() const override { return {
    };}
    QList<Action> actions() const override { return {
        {"Bite", "+5 to hit, reach 5ft., 1d10 +3 piercing and 1d6 lightning"},
        {"Lightning Breath(Recharge 5-6)", "30ft. line 5ft. wide. DC 12 Dex, on fail take 4d10 lightning or half if successful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class AncientGreenDragon : public MonsterType {
public:
    QString name() const override { return "Ancient Green Dragon";}
    int baseAC() const override { return 21;}
    QString hpDice() const override { return "22d20 +154";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 27, 12, 25, 20, 17, 19};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +8, Con +14, Wis +10, Cha +11";}
    QString skills() const override { return "Deception +11, Insight +10, Perception +17, Persuasion +11, Stealth +8";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "poison, poisoned";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 27";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"},
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+15 to hit, reach 15ft., 2d10 +8 piercing and 3d6 poison"},
        {"Claw", "+15 to hit, reach 10ft., 4d6 +8 slashing"},
        {"Tail", "+15 to hit, reach 20ft., 2d8 +8 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 19 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Poison Breath(Recharge 5-6)", "90ft. cone. DC 22 Con Save, on fail take 22d6 poison or half if sucesfull."}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 23 Dex save or take 2d6 +8 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class AdultGreenDragon : public MonsterType {
public:
    QString name() const override { return "Adult Green Dragon";}
    int baseAC() const override { return 19;}
    QString hpDice() const override { return "18d12 +90";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 23, 12, 21, 18, 15, 17};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +6, Con +10, Wis +7, Cha +8";}
    QString skills() const override { return "Deception +8, Insight +7, Perception +12, Persuasion +8, Stealth +6";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "poison, poisoned";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 22";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"},
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+11 to hit, reach 10ft., 2d10 +6 piercing and 2d6 poison"},
        {"Claw", "+11 to hit, reach 5ft., 2d6 +6 slashing"},
        {"Tail", "+11 to hit, reach 15ft., 2d8 +6 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 16 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Poison Breath(Recharge 5-6)", "60ft. cone. DC 18 Con, on fail take 16d6 poison or half if successful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 19 Dex save or take 2d6 +6 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class YoungGreenDragon : public MonsterType {
public:
    QString name() const override { return "Young Green Dragon";}
    int baseAC() const override { return 18;}
    QString hpDice() const override { return "16d10 +48";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 19, 12, 17, 16, 13, 15};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +4, Con +6, Wis +4, Cha +5";}
    QString skills() const override { return "Deception +5, Perception +7, Stealth +4";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "Poison, Poisoned";}
    QString senses() const override { return "blindsight 30ft., darkvision 120ft., p.P. 17";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make three attacks: one with bite and two with claws"},
        {"Bite", "+7 to hit, 2d10 +4 piercing and 2d6 poison"},
        {"Claw", "+7 to hit, 2d6 +4 slashing"},
        {"Poison Breath(Recharge 5-6)", "30ft. cone, DC 14 Con save, on fail 12d6 poison or half if succesful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class GreenDragonWyrmling : public MonsterType {
public:
    QString name() const override { return "Green Dragon Wyrmling";}
    int baseAC() const override { return 17;}
    QString hpDice() const override { return "7d8 +7";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 60;}
    int swim() const override { return 30;}
    Attributes attributes() const override { return Attributes{ 15, 12, 13, 14, 11, 13};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +3, Con +3, Wis +2, Cha +3";}
    QString skills() const override { return "Perception +4, Stealth +3";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "Poison, Poisoned";}
    QString senses() const override { return "blindsight 10ft., darkvision 60ft., p.P. 14";}
    QString languages() const override { return "Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"}
    };}
    QList<Action> actions() const override { return {
        {"Bite", "+4 to hit, 1d10 +2 piercing and 1d6 poison"},
        {"Poison Breath(Recharge 5-6)", "15ft. cone, DC 11 Con save, on fail 6d6 poison or half if succesful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class AncientRedDragon : public MonsterType {
public:
    QString name() const override { return "Ancient Red Dragon";}
    int baseAC() const override { return 22;}
    QString hpDice() const override { return "28d20 +252";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 40;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 30, 10, 29, 18, 15, 23};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +7, Con +16, Wis +9, Cha +13";}
    QString skills() const override { return "Perception +16, Stealth +7";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "fire";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 26";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+17 to hit, reach 15ft., 2d10 +10 piercing and 4d6 fire"},
        {"Claw", "+17 to hit, reach 10ft., 2d6 +10 slashing"},
        {"Tail", "+17 to hit, reach 20ft., 2d8 +10 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 21 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Fire Breath(Recharge 5-6)", "90ft. cone. DC 24 Dex Save, on fail take 26d6 fire or half if sucesfull."}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 25 Dex save or take 2d6 +10 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class AdultRedDragon : public MonsterType {
public:
    QString name() const override { return "Adult Red Dragon";}
    int baseAC() const override { return 19;}
    QString hpDice() const override { return "19d12 +133";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 40;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 27, 10, 25, 16, 13, 21};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +6, Con +13, Wis +7, Cha +11";}
    QString skills() const override { return "Perception +13, Stealth +6";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "fire";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 23";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+14 to hit, reach 10ft., 2d10 +8 piercing and 2d6 fire"},
        {"Claw", "+14 to hit, reach 5ft., 2d6 +8 slashing"},
        {"Tail", "+14 to hit, reach 15ft., 2d8 +8 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 19 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Fire Breath(Recharge 5-6)", "60ft. cone. DC 21 Dex, on fail take 18d6 fire or half if successful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 22 Dex save or take 2d6 +8 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class YoungRedDragon : public MonsterType {
public:
    QString name() const override { return "Young Red Dragon";}
    int baseAC() const override { return 18;}
    QString hpDice() const override { return "17d10 +85";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 40;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 23, 10, 21, 14, 11, 19};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +4, Con +9, Wis +4, Cha +8";}
    QString skills() const override { return "Perception +8, Stealth +4";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "fire";}
    QString senses() const override { return "blindsight 30ft., darkvision 120ft., p.P. 18";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make three attacks: one with bite and two with claws"},
        {"Bite", "+10 to hit, reach 10ft., 2d10 +6 piercing and 1d6 fire"},
        {"Claw", "+10 to hit, reach 5ft., 2d6 +6 slashing"},
        {"Fire Breath(Recharge 5-6)", "30ft. cone. DC 17 Dex, on fail take 16d6 fire or half if successful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class RedDragonWyrmling : public MonsterType {
public:
    QString name() const override { return "Red Dragon Wyrmling";}
    int baseAC() const override { return 17;}
    QString hpDice() const override { return "10d8 +30";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 30;}
    int fly() const override { return 60;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 19, 10, 17, 12, 11, 15};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +2, Con +5, Wis +2, Cha +4";}
    QString skills() const override { return "Perception +4, Stealth +2";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "fire";}
    QString senses() const override { return "blindsight 10ft., darkvision 60ft., p.P. 14";}
    QString languages() const override { return "Draconic";}
    QList<Action> traits() const override { return {
    };}
    QList<Action> actions() const override { return {
        {"Bite", "+6 to hit, reach 5ft., 1d10 +4 piercing and 1d6 fire"},
        {"Fire Breath(Recharge 5-6)", "15ft. cone. DC 13 Dex, on fail take 7d6 fire or half if successful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class AncientWhiteDragon : public MonsterType {
public:
    QString name() const override { return "Ancient White Dragon";}
    int baseAC() const override { return 20;}
    QString hpDice() const override { return "18d20 +144";}
    int speed() const override { return 40;}
    int burrow() const override { return 40;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 26, 10, 26, 10, 13, 14};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +6, Con +14, Wis +7, Cha +8";}
    QString skills() const override { return "Perception +13, Stealth +6";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "cold";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 23";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Ice Walk", "Can move across and climb icy surfaces without ability check. Additionally, difficult terrain composed of ice or snow doesn't cost extra movement."},
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+14 to hit, reach 15ft., 2d10 +8 piercing and 2d8 cold"},
        {"Claw", "+14 to hit, reach 10ft., 2d6 +8 slashing"},
        {"Tail", "+14 to hit, reach 20ft., 2d8 +8 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 16 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Cold Breath(Recharge 5-6)", "90ft. cone. DC 22 Con Save, on fail take 16d8 cold or half if sucesfull."}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 22 Dex save or take 2d6 +8 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class AdultWhiteDragon : public MonsterType {
public:
    QString name() const override { return "Adult White Dragon";}
    int baseAC() const override { return 18;}
    QString hpDice() const override { return "16d12 +96";}
    int speed() const override { return 40;}
    int burrow() const override { return 30;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 22, 10, 22, 8, 12, 12};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +5, Con +11, Wis +6, Cha +6";}
    QString skills() const override { return "Perception +11, Stealth +5";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "cold";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 21";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Ice Walk", "Can move across and climb icy surfaces without ability check. Additionally, difficult terrain composed of ice or snow doesn't cost extra movement."},
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+11 to hit, reach 10ft., 2d10 +6 piercing and 1d8 cold"},
        {"Claw", "+11 to hit, reach 5ft., 2d6 +6 slashing"},
        {"Tail", "+11 to hit, reach 15ft., 2d8 +6 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 14 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Cold Breath(Recharge 5-6)", "60ft. cone. DC 19 Con, on fail take 12d8 cold or half if successful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 19 Dex save or take 2d6 +6 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class YoungWhiteDragon : public MonsterType {
public:
    QString name() const override { return "Young White Dragon";}
    int baseAC() const override { return 17;}
    QString hpDice() const override { return "14d10 +56";}
    int speed() const override { return 40;}
    int burrow() const override { return 20;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 18, 10, 18, 6, 11, 12};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +3, Con +7, Wis +3, Cha +4";}
    QString skills() const override { return "Perception +6, Stealth +3";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "cold";}
    QString senses() const override { return "blindsight 30ft., darkvision 120ft., p.P. 16";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Ice Walk", "Can move across and climb icy surfaces without ability check. Additionally, difficult terrain composed of ice or snow doesn't cost extra movement."},
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make three attacks: one with bite and two with claws"},
        {"Bite", "+7 to hit, reach 10ft., 2d10 +4 piercing and 1d8 cold"},
        {"Claw", "+7 to hit, reach 5ft., 2d6 +4 slashing"},
        {"Cold Breath(Recharge 5-6)", "30ft. cone. DC 15 Con, on fail take 10d8 cold or half if successful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class WhiteDragonWyrmling : public MonsterType {
public:
    QString name() const override { return "White Dragon Wyrmling";}
    int baseAC() const override { return 16;}
    QString hpDice() const override { return "5d8 +10";}
    int speed() const override { return 30;}
    int burrow() const override { return 15;}
    int climb() const override { return 0;}
    int fly() const override { return 60;}
    int swim() const override { return 30;}
    Attributes attributes() const override { return Attributes{ 14, 10, 14, 5, 10, 11};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +2, Con +4, Wis +2, Cha +2";}
    QString skills() const override { return "Perception +4, Stealth +2";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "cold";}
    QString senses() const override { return "blindsight 10ft., darkvision 60ft., p.P. 14";}
    QString languages() const override { return "Draconic";}
    QList<Action> traits() const override { return {
    };}
    QList<Action> actions() const override { return {
        {"Bite", "+4 to hit, reach 5ft., 1d10 +2 piercing and 1d4 cold"},
        {"Cold Breath(Recharge 5-6)", "15ft. cone. DC 12 Con, on fail take 5d8 cold or half if successful"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class AncientBrassDragon : public MonsterType {
public:
    QString name() const override { return "Ancient Brass Dragon";}
    int baseAC() const override { return 20;}
    QString hpDice() const override { return "17d20 +119";}
    int speed() const override { return 40;}
    int burrow() const override { return 40;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 27, 10, 25, 16, 15, 19};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +6, Con +13, Wis +8, Cha +10";}
    QString skills() const override { return "History +9, Perception +14, Persuasion +10, Stealth +6";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "fire";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 24";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+14 to hit, reach 15ft., 2d10 +8 piercing"},
        {"Claw", "+14 to hit, reach 10ft., 2d6 +8 slashing"},
        {"Tail", "+14 to hit, reach 20ft., 2d8 +8 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 18 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Fire Breath", "90ft. line 10ft. wide. DC 21 Dex save, on fail take 16d6 fire or half if sucesfull."},
        {"Sleep Breath", "90ft. cone. DC 21 Con save, on fail fall unconscious for 10min. The effect ends if creature takes damage or someone takes action to wake them up."},
        {"Change Shape", "Polymorph into a humanoid or beast"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 22 Dex save or take 2d6 +8 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class AdultBrassDragon : public MonsterType {
public:
    QString name() const override { return "Adult Brass Dragon";}
    int baseAC() const override { return 18;}
    QString hpDice() const override { return "15d12 +75";}
    int speed() const override { return 40;}
    int burrow() const override { return 30;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 23, 10, 21, 14, 13, 17};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +5, Con +10, Wis +6, Cha +8";}
    QString skills() const override { return "History +7, Perception +11, Persuasion +8, Stealth +5";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "fire";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 21";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+11 to hit, reach 10ft., 2d10 +6 piercing"},
        {"Claw", "+11 to hit, reach 5ft., 2d6 +6 slashing"},
        {"Tail", "+11 to hit, reach 15ft., 2d8 +6 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 16 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Fire Breath", "60ft. line 5ft. wide. DC 18 Dex save, on fail take 13d6 fire or half if sucesfull."},
        {"Sleep Breath", "60ft. cone. DC 18 Con save, on fail fall unconscious for 10min. The effect ends if creature takes damage or someone takes action to wake them up."},
        {"Change Shape", "Polymorph into a humanoid or beast"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 19 Dex save or take 2d6 +6 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class YoungBrassDragon : public MonsterType {
public:
    QString name() const override { return "Young Brass Dragon";}
    int baseAC() const override { return 17;}
    QString hpDice() const override { return "13d10 +39";}
    int speed() const override { return 40;}
    int burrow() const override { return 20;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 19, 10, 17, 12, 11, 15};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +3, Con +6, Wis +3, Cha +5";}
    QString skills() const override { return "Perception +6, Persuasion +5, Stealth +3";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "fire";}
    QString senses() const override { return "blindsight 30ft., darkvision 120ft., p.P. 16";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Makes three attacks: one with bite and two with claws"},
        {"Bite", "+7 to hit, reach 10ft., 2d10 +4 piercing"},
        {"Claw", "+7 to hit, reach 5ft., 2d6 +4 slashing"},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Fire Breath", "40ft. line 5ft. wide. DC 14 Dex save, on fail take 12d6 fire or half if sucesfull."},
        {"Sleep Breath", "30ft. cone. DC 14 Con save, on fail fall unconscious for 5min. The effect ends if creature takes damage or someone takes action to wake them up."}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class BrassDragonWyrmling : public MonsterType {
public:
    QString name() const override { return "Brass Dragon Wyrmling";}
    int baseAC() const override { return 16;}
    QString hpDice() const override { return "3d8 +3";}
    int speed() const override { return 30;}
    int burrow() const override { return 15;}
    int climb() const override { return 0;}
    int fly() const override { return 60;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 15, 10, 13, 10, 11, 13};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +2, Con +3, Wis +2, Cha +3";}
    QString skills() const override { return "Perception +4, Stealth +2";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "fire";}
    QString senses() const override { return "blindsight 10ft., darkvision 60ft., p.P. 14";}
    QString languages() const override { return "Draconic";}
    QList<Action> traits() const override { return {
    };}
    QList<Action> actions() const override { return {
        {"Bite", "+4 to hit, reach 5ft., 1d10 +2 piercing"},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Fire Breath", "20ft. line 5ft. wide. DC 11 Dex save, on fail take 4d6 fire or half if sucesfull."},
        {"Sleep Breath", "15ft. cone. DC 11 Con save, on fail fall unconscious for 1min. The effect ends if creature takes damage or someone takes action to wake them up."}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class AncientBronzeDragon : public MonsterType {
public:
    QString name() const override { return "Ancient Bronze Dragon";}
    int baseAC() const override { return 22;}
    QString hpDice() const override { return "24d20 +192";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 29, 10, 27, 18, 17, 21};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +7, Con +15, Wis +10, Cha +12";}
    QString skills() const override { return "Insight +10, Perception +17, Stealth +7";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "lightning";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 27";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"},
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+16 to hit, reach 15ft., 2d10 +9 piercing"},
        {"Claw", "+16 to hit, reach 10ft., 2d6 +9 slashing"},
        {"Tail", "+16 to hit, reach 20ft., 2d8 +9 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 20 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"lightning Breath", "120ft. line 10ft. wide. DC 23 Dex save, on fail take 16d10 lightning or half if sucesfull."},
        {"Repulsion Breath", "30ft. cone. DC 23 Str save, on fail creature is pushed 60ft. away."},
        {"Change Shape", "Polymorph into a humanoid or beast"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 24 Dex save or take 2d6 +9 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class AdultBronzeDragon : public MonsterType {
public:
    QString name() const override { return "Adult Bronze Dragon";}
    int baseAC() const override { return 19;}
    QString hpDice() const override { return "17d12 +102";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 25, 10, 23, 16, 15, 19};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +5, Con +11, Wis +7, Cha +9";}
    QString skills() const override { return "Insight +7, Perception +12, Stealth +5";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "lightning";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 22";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"},
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+12 to hit, reach 10ft., 2d10 +7 piercing"},
        {"Claw", "+12 to hit, reach 5ft., 2d6 +7 slashing"},
        {"Tail", "+12 to hit, reach 15ft., 2d8 +7 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 17 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"lightning Breath", "90ft. line 5ft. wide. DC 19 Dex save, on fail take 12d10 lightning or half if sucesfull."},
        {"Repulsion Breath", "30ft. cone. DC 19 Str save, on fail creature is pushed 60ft. away."},
        {"Change Shape", "Polymorph into a humanoid or beast"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 20 Dex save or take 2d6 +7 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class YoungBronzeDragon : public MonsterType {
public:
    QString name() const override { return "Young Bronze Dragon";}
    int baseAC() const override { return 18;}
    QString hpDice() const override { return "15d10 +60";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 21, 10, 19, 14, 13, 17};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +3, Con +7, Wis +4, Cha +6";}
    QString skills() const override { return "Insight +4, Perception +7, Stealth +3";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "lightning";}
    QString senses() const override { return "blindsight 30ft., darkvision 120ft., p.P. 17";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Makes three attacks: one with bite and two with claws"},
        {"Bite", "+8 to hit, reach 10ft., 2d10 +5 piercing"},
        {"Claw", "+8 to hit, reach 5ft., 2d6 +5 slashing"},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"lightning Breath", "60ft. line 5ft. wide. DC 15 Dex save, on fail take 10d10 lightning or half if sucesfull."},
        {"Repulsion Breath", "30ft. cone. DC 15 Str save, on fail creature is pushed 40ft. away."},
        {"Change Shape", "Polymorph into a humanoid or beast"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class BronzeDragonWyrmling : public MonsterType {
public:
    QString name() const override { return "Bronze Dragon Wyrmling";}
    int baseAC() const override { return 17;}
    QString hpDice() const override { return "5d8 +10";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 60;}
    int swim() const override { return 30;}
    Attributes attributes() const override { return Attributes{ 17, 10, 15, 12, 11, 15};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +2, Con +4, Wis +2, Cha +4";}
    QString skills() const override { return "Perception +4, Stealth +2";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "lightning";}
    QString senses() const override { return "blindsight 10ft., darkvision 60ft., p.P. 14";}
    QString languages() const override { return "Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"}
    };}
    QList<Action> actions() const override { return {
        {"Bite", "+5 to hit, reach 5ft., 1d10 +3 piercing"},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"lightning Breath", "40ft. line 5ft. wide. DC 12 Dex save, on fail take 3d10 lightning or half if sucesfull."},
        {"Repulsion Breath", "30ft. cone. DC 12 Str save, on fail creature is pushed 30ft. away."}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class AncientCopperDragon : public MonsterType {
public:
    QString name() const override { return "Ancient Copper Dragon";}
    int baseAC() const override { return 21;}
    QString hpDice() const override { return "20d20 +140";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 40;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 27, 12, 25, 20, 17, 19};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +8, Con +14, Wis +10, Cha +11";}
    QString skills() const override { return "Deception +11, Perception +17, Stealth +8";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "acid";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 27";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+15 to hit, reach 15ft., 2d10 +8 piercing"},
        {"Claw", "+15 to hit, reach 10ft., 2d6 +8 slashing"},
        {"Tail", "+15 to hit, reach 20ft., 2d8 +8 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 19 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Acid Breath", "90ft. line 10ft. wide. DC 22 Dex save, on fail take 14d8 acid or half if sucesfull."},
        {"Slowing Breath", "90ft. cone. DC 22 Con save, on fail, for 1min, creature can't use reactions. Its speed is halved and it can't make more than one attack on its turn. Additionally the creature can only use an action or a bonus action. The creature can repeat the save at the end of its turn, ending the effect if successful."},
        {"Change Shape", "Polymorph into a humanoid or beast"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 23 Dex save or take 2d6 +8 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class AdultCopperDragon : public MonsterType {
public:
    QString name() const override { return "Adult Copper Dragon";}
    int baseAC() const override { return 18;}
    QString hpDice() const override { return "16d12 +80";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 40;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 23, 12, 21, 18, 15, 17};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +6, Con +10, Wis +7, Cha +8";}
    QString skills() const override { return "Deception +8, Perception +12, Stealth +6";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "acid";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 22";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+11 to hit, reach 10ft., 2d10 +6 piercing"},
        {"Claw", "+11 to hit, reach 5ft., 2d6 +6 slashing"},
        {"Tail", "+11 to hit, reach 15ft., 2d8 +6 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 16 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Acid Breath", "60ft. line 5ft. wide. DC 18 Dex save, on fail take 12d8 acid or half if sucesfull."},
        {"Slowing Breath", "60ft. cone. DC 18 Con save, on fail, for 1min, creature can't use reactions. Its speed is halved and it can't make more than one attack on its turn. Additionally the creature can only use an action or a bonus action. The creature can repeat the save at the end of its turn, ending the effect if successful."},
        {"Change Shape", "Polymorph into a humanoid or beast"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 19 Dex save or take 2d6 +6 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class YoungCopperDragon : public MonsterType {
public:
    QString name() const override { return "Young Copper Dragon";}
    int baseAC() const override { return 17;}
    QString hpDice() const override { return "14d10 +42";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 40;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 19, 12, 17, 16, 13, 15};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +4, Con +6, Wis +4, Cha +5";}
    QString skills() const override { return "Deception +5, Perception +7, Stealth +4";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "acid";}
    QString senses() const override { return "blindsight 30ft., darkvision 120ft., p.P. 17";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make three attacks: one with bite and two with claws"},
        {"Bite", "+7 to hit, reach 10ft., 2d10 +4 piercing"},
        {"Claw", "+7 to hit, reach 5ft., 2d6 +4 slashing"},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Acid Breath", "40ft. line 5ft. wide. DC 14 Dex save, on fail take 9d8 acid or half if sucesfull."},
        {"Slowing Breath", "30ft. cone. DC 14 Con save, on fail, for 1min, creature can't use reactions. Its speed is halved and it can't make more than one attack on its turn. Additionally the creature can only use an action or a bonus action. The creature can repeat the save at the end of its turn, ending the effect if successful."},
        {"Change Shape", "Polymorph into a humanoid or beast"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class CopperDragonWyrmling : public MonsterType {
public:
    QString name() const override { return "Copper Dragon Wyrmling";}
    int baseAC() const override { return 16;}
    QString hpDice() const override { return "4d8 +4";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 30;}
    int fly() const override { return 60;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 15, 12, 13, 14, 11, 13};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +3, Con +3, Wis +2, Cha +3";}
    QString skills() const override { return "Perception +4, Stealth +3";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "acid";}
    QString senses() const override { return "blindsight 10ft., darkvision 60ft., p.P. 14";}
    QString languages() const override { return "Draconic";}
    QList<Action> traits() const override { return {
    };}
    QList<Action> actions() const override { return {
        {"Bite", "+4 to hit, reach 5ft., 1d10 +2 piercing"},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Acid Breath", "20ft. line 5ft. wide. DC 11 Dex save, on fail take 4d8 acid or half if sucesfull."},
        {"Slowing Breath", "15ft. cone. DC 11 Con save, on fail, for 1min, creature can't use reactions. Its speed is halved and it can't make more than one attack on its turn. Additionally the creature can only use an action or a bonus action. The creature can repeat the save at the end of its turn, ending the effect if successful."}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class AncientGoldDragon : public MonsterType {
public:
    QString name() const override { return "Ancient Gold Dragon";}
    int baseAC() const override { return 22;}
    QString hpDice() const override { return "28d20 +252";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 30, 14, 29, 18, 17, 28};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +9, Con +16, Wis +10, Cha +16";}
    QString skills() const override { return "Insight +10, Perception +17, Persuasion +16, Stealth +9";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "fire";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 27";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"},
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+17 to hit, reach 15ft., 2d10 +10 piercing"},
        {"Claw", "+17 to hit, reach 10ft., 2d6 +10 slashing"},
        {"Tail", "+17 to hit, reach 20ft., 2d8 +10 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 24 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Fire Breath", "90ft. cone. DC 24 Dex save, on fail take 13d10 fire or half if sucesfull."},
        {"Weakening Breath", "90ft. cone. DC 24 Str save, on fail, for 1min, creature has disadvantage on Str-based attack rolls, Str-checks and Str saves, A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success."},
        {"Change Shape", "Polymorph into a humanoid or beast"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 25 Dex save or take 2d6 +10 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class AdultGoldDragon : public MonsterType {
public:
    QString name() const override { return "Adult Gold Dragon";}
    int baseAC() const override { return 19;}
    QString hpDice() const override { return "19d12 +133";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 27, 14, 25, 16, 15, 24};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +8, Con +13, Wis +8, Cha +13";}
    QString skills() const override { return "Insight +8, Perception +14, Persuasion +13, Stealth +8";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "fire";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 24";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"},
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+14 to hit, reach 10ft., 2d10 +8 piercing"},
        {"Claw", "+14 to hit, reach 5ft., 2d6 +8 slashing"},
        {"Tail", "+14 to hit, reach 15ft., 2d8 +8 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 21 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Fire Breath", "60ft. cone. DC 21 Dex save, on fail take 12d10 fire or half if sucesfull."},
        {"Weakening Breath", "60ft. cone. DC 21 Str save, on fail, for 1min, creature has disadvantage on Str-based attack rolls, Str-checks and Str saves, A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success."},
        {"Change Shape", "Polymorph into a humanoid or beast"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 22 Dex save or take 2d6 +8 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class YoungGoldDragon : public MonsterType {
public:
    QString name() const override { return "Young Gold Dragon";}
    int baseAC() const override { return 18;}
    QString hpDice() const override { return "17d10 +85";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 40;}
    Attributes attributes() const override { return Attributes{ 23, 14, 21, 16, 13, 20};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +6, Con +9, Wis +5, Cha +9";}
    QString skills() const override { return "Insight +5, Perception +9, Persuasion +9, Stealth +6";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "fire";}
    QString senses() const override { return "blindsight 30ft., darkvision 120ft., p.P. 19";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make three attacks: one with bite and two with claws"},
        {"Bite", "+10 to hit, reach 10ft., 2d10 +6 piercing"},
        {"Claw", "+10 to hit, reach 5ft., 2d6 +6 slashing"},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Fire Breath", "30ft. cone. DC 17 Dex save, on fail take 10d10 fire or half if sucesfull."},
        {"Weakening Breath", "30ft. cone. DC 17 Str save, on fail, for 1min, creature has disadvantage on Str-based attack rolls, Str-checks and Str saves, A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success."}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class GoldDragonWyrmling : public MonsterType {
public:
    QString name() const override { return "Gold Dragon Wyrmling";}
    int baseAC() const override { return 17;}
    QString hpDice() const override { return "8d8 +24";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 60;}
    int swim() const override { return 30;}
    Attributes attributes() const override { return Attributes{ 19, 14, 17, 14, 11, 16};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +4, Con +5, Wis +2, Cha +5";}
    QString skills() const override { return "Perception +4, Stealth +4";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "fire";}
    QString senses() const override { return "blindsight 10ft., darkvision 60ft., p.P. 14";}
    QString languages() const override { return "Draconic";}
    QList<Action> traits() const override { return {
        {"Amphibious", "Can breath air and water"}
    };}
    QList<Action> actions() const override { return {
        {"Bite", "+6 to hit, reach 5ft., 1d10 +4 piercing"},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Fire Breath", "15ft. cone. DC 13 Dex save, on fail take 4d10 fire or half if sucesfull."},
        {"Weakening Breath", "15ft. cone. DC 13 Str save, on fail, for 1min, creature has disadvantage on Str-based attack rolls, Str-checks and Str saves, A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success."}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class AncientSilverDragon : public MonsterType {
public:
    QString name() const override { return "Ancient Silver Dragon";}
    int baseAC() const override { return 22;}
    QString hpDice() const override { return "25d20 +225";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 30, 10, 29, 18, 15, 23};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +7, Con +16, Wis +9, Cha +13";}
    QString skills() const override { return "Arcana +11, History +11, Perception +16, Stealth +7";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "cold";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 26";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+17 to hit, reach 15ft., 2d10 +10 piercing"},
        {"Claw", "+17 to hit, reach 10ft., 2d6 +10 slashing"},
        {"Tail", "+17 to hit, reach 20ft., 2d8 +10 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 24 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Cold Breath", "90ft. cone. DC 24 Con save, on fail take 15d8 cold or half if sucessful."},
        {"Paralyzing Breath", "90ft. cone. DC 24 Con save, on fail, become paralyzed for 1min. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success."},
        {"Change Shape", "Polymorph into a humanoid or beast"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 25 Dex save or take 2d6 +10 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class AdultSilverDragon : public MonsterType {
public:
    QString name() const override { return "Adult Silver Dragon";}
    int baseAC() const override { return 19;}
    QString hpDice() const override { return "18d12 +126";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 27, 10, 25, 16, 13, 21};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +5, Con +12, Wis +6, Cha +10";}
    QString skills() const override { return "Arcana +8, History +8, Perception +11, Stealth +5";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "cold";}
    QString senses() const override { return "blindsight 60ft., darkvision 120ft., p.P. 21";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
        {"Legendary Resistance(3/day)", "If fails a saving throws, it can choose to succeed insted"}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Can use its Frightful Presence. It then makes three attacks: one with bite and two with claws"},
        {"Bite", "+13 to hit, reach 10ft., 2d10 +8 piercing"},
        {"Claw", "+13 to hit, reach 5ft., 2d6 +8 slashing"},
        {"Tail", "+13 to hit, reach 15ft., 2d8 +8 bludgeoning"},
        {"Frightful Presence", "Each creature of the dragon's choice that is within 120ft. of the dragon and aware of it must succeed on a DC 18 Wis save or become frightened for 1 minute. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success. If a creature's saving throw is successful or the effect ends for it, the creature is immune to the dragon's Frightful Presence for the next 24 hours."},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Cold Breath", "60ft. cone. DC 20 Con save, on fail take 13d8 cold or half if sucessful."},
        {"Paralyzing Breath", "60ft. cone. DC 20 Con save, on fail, become paralyzed for 1min. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success."},
        {"Change Shape", "Polymorph into a humanoid or beast"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
        {"Detect", "Make a Perception check"},
        {"Tail Attack", "Make a tail attack"},
        {"Wing Attack(costs 2)", "Each creature within 15ft. must succeed DC 21 Dex save or take 2d6 +8 bludgeoning and be knocked prone. The dragon can then fly up to half its flying speed."}
    };}
};

class YoungSilverDragon : public MonsterType {
public:
    QString name() const override { return "Young Silver Dragon";}
    int baseAC() const override { return 18;}
    QString hpDice() const override { return "16d10 +80";}
    int speed() const override { return 40;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 80;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 23, 10, 21, 14, 11, 19};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +4, Con +9, Wis +4, Cha +8";}
    QString skills() const override { return "Arcana +6, History +6, Perception +8, Stealth +4";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "cold";}
    QString senses() const override { return "blindsight 30ft., darkvision 120ft., p.P. 18";}
    QString languages() const override { return "Common, Draconic";}
    QList<Action> traits() const override { return {
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make three attacks: one with bite and two with claws"},
        {"Bite", "+10 to hit, reach 10ft., 2d10 +6 piercing"},
        {"Claw", "+10 to hit, reach 5ft., 2d6 +6 slashing"},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Cold Breath", "30ft. cone. DC 17 Con save, on fail take 12d8 cold or half if sucessful."},
        {"Paralyzing Breath", "30ft. cone. DC 17 Con save, on fail, become paralyzed for 1min. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success."}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class SilverDragonWyrmling : public MonsterType {
public:
    QString name() const override { return "Silver Dragon Wyrmling";}
    int baseAC() const override { return 17;}
    QString hpDice() const override { return "6d8 +18";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 60;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 19, 10, 17, 12, 11, 15};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +2, Con +5, Wis +2, Cha +4";}
    QString skills() const override { return "Perception +4, Stealth +2";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "cold";}
    QString senses() const override { return "blindsight 10ft., darkvision 60ft., p.P. 14";}
    QString languages() const override { return "Draconic";}
    QList<Action> traits() const override { return {
    };}
    QList<Action> actions() const override { return {
        {"Bite", "+6 to hit, reach 5ft., 1d10 +4 piercing"},
        {"Breath(Recharge 5-6)", "Use one of the following breaths"},
        {"Cold Breath", "15ft. cone. DC 13 Con save, on fail take 4d8 cold or half if sucessful."},
        {"Paralyzing Breath", "15ft. cone. DC 13 Con save, on fail, become paralyzed for 1min. A creature can repeat the save at the end of each of its turns, ending the effect on itself on a success."}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};

class VampireSpawn : public MonsterType {
public:
    QString name() const override { return "Vampire Spawn";}
    int baseAC() const override { return 15;}
    QString hpDice() const override { return "11d8 +33";}
    int speed() const override { return 30;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ 16, 16, 16, 11, 10, 12};} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "Dex +6, Wis +3";}
    QString skills() const override { return "Perception +3, Stealth +6";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "necrotic; bludgeoning, piercing and slashin from nonmagical attacks";}
    QString immunities() const override { return "";}
    QString senses() const override { return "darkvision 60ft., p.P. 13";}
    QString languages() const override { return "languages it knew in life";}
    QList<Action> traits() const override { return {
        {"Regeneration", "Regain 10hp at the start of its turn, if it has atleast 1hp and isn't standing in sunlight or running water. Taking radiant stops regeneration next turn"},
        {"Spider Climb", "Can climb difficult surfaces, including upside down on ceilings, without ability checks"},
        {"Forbiddance", "Can't enter a residence without and invitation from an occupant."},
        {"Harmed by Running Water", "Take 20 acid when ending its turn in running water."},
        {"Stake to the Heart", "Is destroyed if a piercing weapon made of wood is driven into its heart while incapacitated in its resting place."},
        {"Sunlight Hypersensitivity", "Take 20 radiant when it starts its turn in sunlight. While in sunlight, it has disadvantage on attack rolls and ability checks."}
    };}
    QList<Action> actions() const override { return {
        {"Multiattack", "Make two attacks, only one can be bite"},
        {"Claws", "+6 to hit, reach 5ft., 2d4 +3 slashing. Instead of doing damage can grapple(escape DC 13)"},
        {"Bite", "+6 to hit, reach 5ft., 1d6 +3 piercing and 2d6 necrotic. Vampire heals for the necrotic amount it deals. Target has to be willing, grappled, incapacitated or restrained"}
    };}
    QList<Action> reactions() const override { return {
    };}
    QList<Action> legendaries() const override { return {
    };}
};













/*
class  : public MonsterType {
public:
    QString name() const override { return "";}
    int baseAC() const override { return ;}
    QString hpDice() const override { return "";}
    int speed() const override { return 0;}
    int burrow() const override { return 0;}
    int climb() const override { return 0;}
    int fly() const override { return 0;}
    int swim() const override { return 0;}
    Attributes attributes() const override { return Attributes{ , , , , , };} //str, dex, con, int, wis, cha
    QString saving_throws() const override { return "";}
    QString skills() const override { return "";}
    QString vulnerabilities() const override { return "";}
    QString resistances() const override { return "";}
    QString immunities() const override { return "";}
    QString senses() const override { return ", p.P. ";}
    QString languages() const override { return "";}
    QList<Action> traits() const override { return {
        {"", ""},
        {"", ""}
    };}
    QList<Action> actions() const override { return {
        {"", "+ to hit, "},
        {"", "+ to hit, "}
    };}
    QList<Action> reactions() const override { return {
        {"", ""},
        {"", ""}
    };}
    QList<Action> legendaries() const override { return {
        {"", ""},
        {"", ""}
    };}
};*/
