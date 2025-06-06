#pragma once
#include <qstring.h>

struct MonsterAction {
    QString name;
    int toHitModifier;
    QString damageDice;
    int damageModifier;
    QString damageType;
};
