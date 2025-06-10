#include "MonsterFactory.h"

std::shared_ptr<MonsterType> createMonsterType(const QString& name) {
    if (name == "Goblin") return std::make_shared<Goblin>();
    if (name == "Goblin Boss") return std::make_shared<GoblinBoss>();
    if (name == "Orc") return std::make_shared<Orc>();
    return nullptr;
}
