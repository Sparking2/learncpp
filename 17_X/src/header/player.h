#pragma once

#include "creature.h";

class Player : public Creature {
protected:
    int m_level{ 1 };

public:
    // Constructor
    Player(std::string);

    // Others
    int getLevel();
    void levelUp();
    bool hasWon();
};