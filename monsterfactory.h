#pragma once
#include <QString>
#include <memory>
#include "MonsterType.h"

std::shared_ptr<MonsterType> createMonsterType(const QString& name);
