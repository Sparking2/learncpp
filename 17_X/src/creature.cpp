#pragma once

#include "header/creature.h"

// Constructor
Creature::Creature(std::string name, char symbol, int hp, int dmg, int gold)
    : m_name{ name },
    m_symbol{ symbol },
    m_hp{ hp },
    m_dmg{ dmg },
    m_gold{ gold }
{}

/* Getters */
std::string Creature::getName() {
    return m_name;
}
char Creature::getSymbol() {
    return m_symbol;
}
int Creature::getHp() {
    return m_hp;
}
int Creature::getDmg() {
    return m_dmg;
}
int Creature::getGold() {
    return m_gold;
}

// Others
void Creature::reduceHealth(int dmg) {
    m_hp -= dmg;
}
bool Creature::isDead() {
    return m_hp <= 0;
}
void Creature::addGold(int gold) {
    m_gold += gold;
}

