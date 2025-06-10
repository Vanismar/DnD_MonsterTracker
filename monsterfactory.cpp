#include "MonsterFactory.h"

std::shared_ptr<MonsterType> createMonsterType(const QString& name) {
    if (name == "Goblin") return std::make_shared<Goblin>();
    if (name == "Goblin Boss") return std::make_shared<GoblinBoss>();
    if (name == "Orc") return std::make_shared<Orc>();
    if (name == "Spectator") return std::make_shared<Spectator>();
    if (name == "Twig Blight") return std::make_shared<TwigBlight>();
    return nullptr;
}
