#include "MonsterInstance.h"
#include <QRegularExpression>
#include <random>

static int randomBetween(int min, int max) {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}

MonsterInstance::MonsterInstance(std::shared_ptr<MonsterType> type) {
    name = type->name();
    hpDice = type->hpDice();  // save dice formula
    maxHp = hp = rollDice(hpDice);
    ac = type->baseAC() + randomBetween(-1, 1);
}

int MonsterInstance::rollDice(const QString& dice) {
    QRegularExpression regex(R"((\d+)[dD](\d+)(?:\s*([+-])\s*(\d+))?)");
    QRegularExpressionMatch match = regex.match(dice.trimmed());

    if (!match.hasMatch()) return 0;

    int rolls = match.captured(1).toInt();
    int sides = match.captured(2).toInt();
    QString sign = match.captured(3);
    int modifier = match.captured(4).toInt();

    if (sign == "-") modifier *= -1;
    else if (sign.isEmpty()) modifier = 0;

    int total = 0;
    for (int i = 0; i < rolls; ++i) {
        total += randomBetween(1, sides);
    }

    return total + modifier;
}
