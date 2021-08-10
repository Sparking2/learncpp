#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "header/player.h"
#include "header/monster.h"
#include "header/tool.h"

void attackMonster(Player& player, Monster& monster) {
    if (player.isDead())
        return;

    std::cout << "You hit the " << monster.getName() << " for " << player.getDmg() << " damage.\n";

    monster.reduceHealth(player.getDmg());

    if (monster.isDead()) {
        std::cout << "You killed the " << monster.getName() << ".\n";
        player.levelUp();
        std::cout << "You are now level " << player.getLevel() << ".\n";
        std::cout << "You found " << monster.getGold() << " gold.\n";
        player.addGold(monster.getGold());
    }
}

void attackPlayer(Monster& monster, Player& player) {
    if (monster.isDead())
        return;

    player.reduceHealth(monster.getDmg());

    std::cout << "The " << monster.getName() << " hit you for " << monster.getDmg() << " damage.\n";
}

void fightMonster(Player& player) {
    Monster monster{ Monster::getRandomMonster() };
    std::cout << "You have encountered a " << monster.getName() << " (" << monster.getSymbol() << ")/\n";

    while (!monster.isDead() && !player.isDead()) {
        std::cout << "(R)un or (F)ight:";
        char input{};
        std::cin >> input;
        if (input == 'R' || input == 'r') {
            if (Tools::getRandomNumber(1, 2) == 1) {
                std::cout << "You successfully fled.\n";
                return;
            }
            else {
                std::cout << "You failed to flee.\n";
                attackPlayer(monster, player);
                continue;
            }
        }
        if (input == 'f' || input == 'F') {
            attackMonster(player, monster);
            attackPlayer(monster, player);
        }
    }
}

int main() {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();

    std::cout << "Welcome player to !D&D \n\nPlease enter your name:";
    std::string n;
    std::cin >> n;

    Player p{ n };
    std::cout << "Hello there " << p.getName() << "\n";

    while (!p.isDead() && !p.hasWon())
        fightMonster(p);

    if (p.isDead()) {
        std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
        std::cout << "Too bad, you can't take it with you :(\n";
    }
    else {
        std::cout << "You beat the Dungeon with " << p.getGold() << " gold!, go and enjoy a Beer!.\n";
    }

    return 0;
}