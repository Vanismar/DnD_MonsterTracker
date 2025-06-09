#pragma once
#include <QString>
#include <memory>
#include "MonsterType.h"

class MonsterInstance {
public:
    MonsterInstance(std::shared_ptr<MonsterType> type);

    QString name;
    QString hpDice;
    int hp;
    int maxHp;
    int ac;
    int speed;
    int climb;
    int fly;

private:
    int rollDice(const QString& dice);
};
