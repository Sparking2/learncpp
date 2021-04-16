// Quiz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>

enum class MonsterType {
	ogre,
	dragon,
	orc,
	giant_spider,
	slime
};

struct Monster {
	MonsterType type;
	std::string name;
	int health;
};

std::string getMonsterTypeString(MonsterType type) {
	switch (type) {
	case MonsterType::ogre:
		return "Ogre";
	case MonsterType::dragon:
		return "Dragon";
	case MonsterType::orc:
		return "Orc";
	case MonsterType::giant_spider:
		return "Giant Spider";
	case MonsterType::slime:
		return "Slime";
	}
	return "Unknow";
}

void printMonster(Monster monster) {
	std::cout << "This " << getMonsterTypeString(monster.type) << " is named " << monster.name << " and has " << monster.health << " health\n";
}

int main() {
	Monster ogre{ MonsterType::ogre, "Torg", 145 };
	Monster slime{ MonsterType::slime, "Blurp", 23 };

	printMonster(ogre);
	printMonster(slime);

	return 0;
}

