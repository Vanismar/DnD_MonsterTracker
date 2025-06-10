#include "MonsterFactory.h"

std::shared_ptr<MonsterType> createMonsterType(const QString& name) {
    if (name == "Goblin") return std::make_shared<Goblin>();
    if (name == "Goblin Boss") return std::make_shared<GoblinBoss>();
    if (name == "Orc") return std::make_shared<Orc>();
    if (name == "Spectator") return std::make_shared<Spectator>();
    if (name == "Twig Blight") return std::make_shared<TwigBlight>();
    if (name == "Bugbear") return std::make_shared<Bugbear>();
    if (name == "Bugbear Chief") return std::make_shared<BugbearChief>();
    if (name == "Doppelganger") return std::make_shared<Doppelganger>();
    return nullptr;
}
