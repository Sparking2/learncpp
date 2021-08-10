#pragma once

#include <iostream>

class Creature {
protected:
    std::string m_name;
    char m_symbol;
    int m_hp;
    int m_dmg;
    int m_gold;

public:
    // Constructor
    Creature(std::string, char, int, int, int);

    /**
    ***  Getters
    **/

    std::string getName();
    char getSymbol();
    int getHp();
    int getDmg();
    int getGold();

    // Others
    void reduceHealth(int);
    bool isDead();
    void addGold(int);
};
