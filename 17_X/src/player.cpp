#pragma once

#include "header/player.h"

Player::Player(std::string name)
    : Creature(name, '@', 10, 1, 0)
{}

int Player::getLevel() {
    return m_level;
}

void Player::levelUp() {
    ++m_level;
    ++m_dmg;
}

bool Player::hasWon() {
    return m_level >= 20;
}