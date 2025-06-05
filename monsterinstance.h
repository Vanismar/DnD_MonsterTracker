#pragma once
#include <QString>
#include <memory>
#include "MonsterType.h"

class MonsterInstance {
public:
    MonsterInstance(std::shared_ptr<MonsterType> type);

    QString name;
    int hp;
    int maxHp;
    int ac;

private:
    int rollDice(const QString& dice);
};
