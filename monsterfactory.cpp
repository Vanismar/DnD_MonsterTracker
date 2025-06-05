#include "MonsterFactory.h"
#include "Goblin.h"
#include "Orc.h"
#include "Dragon.h"

std::shared_ptr<MonsterType> createMonsterType(const QString& name) {
    if (name == "Goblin") return std::make_shared<Goblin>();
    if (name == "Orc") return std::make_shared<Orc>();
    if (name == "Dragon") return std::make_shared<Dragon>();
    return nullptr;
}
