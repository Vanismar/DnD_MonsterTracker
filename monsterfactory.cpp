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
    if (name == "Grick") return std::make_shared<Grick>();
    if (name == "Grick Alpha") return std::make_shared<GrickAlpha>();
    if (name == "Hobgoblin") return std::make_shared<Hobgoblin>();
    if (name == "Hobgoblin Captain") return std::make_shared<HobgoblinCaptain>();
    if (name == "Hobgoblin Warlord") return std::make_shared<HobgoblinWarlord>();
    if (name == "Mimic") return std::make_shared<Mimic>();
    if (name == "Nothic") return std::make_shared<Nothic>();
    if (name == "Ochre Jelly") return std::make_shared<OchreJelly>();
    if (name == "Gray Ooze") return std::make_shared<GrayOoze>();
    if (name == "Gelatinous Cube") return std::make_shared<GelatinousCube>();
    if (name == "Black Pudding") return std::make_shared<BlackPudding>();
    if (name == "Orc War Chief") return std::make_shared<OrcWarChief>();
    if (name == "Orc Eye of Gruumsh") return std::make_shared<OrcEyeofGruumsh>();
    if (name == "Orog") return std::make_shared<Orog>();
    if (name == "Owlbear") return std::make_shared<Owlbear>();
    if (name == "Skeleton") return std::make_shared<Skeleton>();
    if (name == "Minotaur Skeleton") return std::make_shared<MinotaurSkeleton>();
    if (name == "Warhorse Skeleton") return std::make_shared<WarhorseSkeleton>();
    if (name == "Silver Dragon Wyrmling") return std::make_shared<SilverDragonWyrmling>();
    if (name == "Gold Dragon Wyrmling") return std::make_shared<GoldDragonWyrmling>();
    if (name == "Copper Dragon Wyrmling") return std::make_shared<CopperDragonWyrmling>();
    if (name == "Bronze Dragon Wyrmling") return std::make_shared<BronzeDragonWyrmling>();
    if (name == "Brass Dragon Wyrmling") return std::make_shared<BrassDragonWyrmling>();
    if (name == "White Dragon Wyrmling") return std::make_shared<WhiteDragonWyrmling>();
    if (name == "Red Dragon Wyrmling") return std::make_shared<RedDragonWyrmling>();
    if (name == "Green Dragon Wyrmling") return std::make_shared<GreenDragonWyrmling>();
    if (name == "Blue Dragon Wyrmling") return std::make_shared<BlueDragonWyrmling>();
    if (name == "Black Dragon Wyrmling") return std::make_shared<BlackDragonWyrmling>();
    if (name == "Young Silver Dragon") return std::make_shared<YoungSilverDragon>();
    if (name == "Young Gold Dragon") return std::make_shared<YoungGoldDragon>();
    if (name == "Young Copper Dragon") return std::make_shared<YoungCopperDragon>();
    if (name == "Young Bronze Dragon") return std::make_shared<YoungBronzeDragon>();
    if (name == "Young Brass Dragon") return std::make_shared<YoungBrassDragon>();
    if (name == "Young White Dragon") return std::make_shared<YoungWhiteDragon>();
    if (name == "Young Red Dragon") return std::make_shared<YoungRedDragon>();
    if (name == "Young Green Dragon") return std::make_shared<YoungGreenDragon>();
    if (name == "Young Blue Dragon") return std::make_shared<YoungBlueDragon>();
    if (name == "Young Black Dragon") return std::make_shared<YoungBlackDragon>();
    if (name == "Adult Silver Dragon") return std::make_shared<AdultSilverDragon>();
    if (name == "Adult Gold Dragon") return std::make_shared<AdultGoldDragon>();
    if (name == "Adult Copper Dragon") return std::make_shared<AdultCopperDragon>();
    if (name == "Adult Bronze Dragon") return std::make_shared<AdultBronzeDragon>();
    if (name == "Adult Brass Dragon") return std::make_shared<AdultBrassDragon>();
    if (name == "Adult White Dragon") return std::make_shared<AdultWhiteDragon>();
    if (name == "Adult Red Dragon") return std::make_shared<AdultRedDragon>();
    if (name == "Adult Green Dragon") return std::make_shared<AdultGreenDragon>();
    if (name == "Adult Blue Dragon") return std::make_shared<AdultBlueDragon>();
    if (name == "Adult Black Dragon") return std::make_shared<AdultBlackDragon>();
    if (name == "Ancient Silver Dragon") return std::make_shared<AncientSilverDragon>();
    if (name == "Ancient Gold Dragon") return std::make_shared<AncientGoldDragon>();
    if (name == "Ancient Copper Dragon") return std::make_shared<AncientCopperDragon>();
    if (name == "Ancient Bronze Dragon") return std::make_shared<AncientBronzeDragon>();
    if (name == "Ancient Brass Dragon") return std::make_shared<AncientBrassDragon>();
    if (name == "Ancient White Dragon") return std::make_shared<AncientWhiteDragon>();
    if (name == "Ancient Red Dragon") return std::make_shared<AncientRedDragon>();
    if (name == "Ancient Green Dragon") return std::make_shared<AncientGreenDragon>();
    if (name == "Ancient Blue Dragon") return std::make_shared<AncientBlueDragon>();
    if (name == "Ancient Black Dragon") return std::make_shared<AncientBlackDragon>();
    if (name == "Vampire Spawn") return std::make_shared<VampireSpawn>();
    if (name == "Vampire Fledgling") return std::make_shared<VampireFledgling>();
    if (name == "Vampire Knight") return std::make_shared<VampireKnight>();
    if (name == "Vampire Baron") return std::make_shared<VampireBaron>();
    if (name == "Vampire Viscount") return std::make_shared<VampireViscount>();
    if (name == "Vampire Count") return std::make_shared<VampireCount>();
    if (name == "Vampire Duke") return std::make_shared<VampireDuke>();
    if (name == "Swarm of Bats") return std::make_shared<SwarmofBats>();
    if (name == "Swarm of Rats") return std::make_shared<SwarmofRats>();
    if (name == "Wolf") return std::make_shared<Wolf>();








    return nullptr;
}
