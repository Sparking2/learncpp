#pragma once

#include "creature.h"

class Monster : public Creature {
public:
    enum class Type {
        dragon,
        orc,
        slime,
        max_types
    };

private:
    static const Creature& getDefaultCreature(Type);

public:
    Monster(Type);
    static Monster getRandomMonster();
};
