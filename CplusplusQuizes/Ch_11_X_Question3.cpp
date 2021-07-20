//Question #3
//Let’s create a random monster generator.
// This one should be fun.
//a) First, let’s create an enumeration of monster types named MonsterType.
//Include the following monster types : Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie.
//Add an additional max_monster_types enum so we can count how many enumerators there are.

//b) Now, let’s create our Monster class.
//Our Monster will have 4 attributes
//(member variables) : a type(MonsterType), a name(std::string), a roar(std::string), and the number of hit points(int).
//Create a Monster class that has these 4 member variables.

//c) enum MonsterType is specific to Monster, so move the enum inside the class as a public declaration.
//When the enum is inside the class the “Monster” in “MonsterType” is redundant, it can be removed.

//d) Create a constructor that allows you to initialize all of the member variables.

//e) Now we want to be able to print our monster so we can validate it’s correct.
//To do that, we’re going to need to write a function that converts a Monster::Type into a string.
//Write that function(called getTypeString()), as well as a print() member function.

//f) Now we can create a random monster generator.
//Let’s consider how our MonsterGenerator class will work.
//Ideally, we’ll ask it to give us a Monster, and it will create a random one for us.
//We don’t need more than one MonsterGenerator.
//This is a good candidate for a static class (one in which all functions are static).
//Create a static MonsterGenerator class.
//Create a static function named generateMonster().
//This should return a Monster.
//For now, make it return anonymous Monster(Monster::Type::skeleton, “Bones”, “ * rattle * ”, 4);

//g) Now, MonsterGenerator needs to generate some random attributes.
//To do that, we’ll need to make use of this handy function :

#include <iostream>
#include <string>
#include <algorithm>
#include <array>

class Monster {
public:
	enum class Type {
		dragon,
		goblin,
		ogre,
		orc,
		skeleton,
		troll,
		vampire,
		zombie,
		max_monster_types
	};

private:
	Type m_type{};
	std::string m_name{};
	std::string m_roar{};
	int m_hitPoints{};

public:
	Monster(Type type, std::string name, std::string roar, int hp)
		: m_type{ type }, m_name{ name }, m_roar{ roar }, m_hitPoints{ hp }
	{}

private:
	std::string getTypeString() {
		switch (m_type)
		{
		case Monster::Type::dragon: return "dragon";
		case Monster::Type::goblin: return "goblin";
		case Monster::Type::ogre: return "ogre";
		case Monster::Type::orc: return "orc";
		case Monster::Type::skeleton: return "skeleton";
		case Monster::Type::troll: return "troll";
		case Monster::Type::vampire: return "vampire";
		case Monster::Type::zombie: return "zombie";
		default: return "???";
		}
	}

public:
	void print() {
		std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << "\n";
	}
};

static class MonsterGenerator {

public:


	static int getRandomNumber(int min, int max) {
		static constexpr double fraction{ 1.0 / (static_cast<double>(RAND_MAX) + 1.0) };
		return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
	}

	static Monster generateMonster() {
		static constexpr std::array names{ "Bones", "Alfredo", "Rodrigo", "Frankenstein", "Raul", "ThroatSlicer" };
		static constexpr std::array roars{ "ROAR!!", "Burp", "Arrrg", "Tssssss", "Rackt", "He,he,he" };

		auto type{ static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::max_monster_types) - 1) )};
		auto name{ names[getRandomNumber(0,5)] };
		auto roar{ roars[getRandomNumber(0,5)] };
		auto hp{ getRandomNumber(1,100) };

		return Monster{ type, name, roar, hp };
	};

};

int Ch_11_X_Question3() {
	std::srand(static_cast<unsigned int>(std::time(nullptr))); // set initial seed value to system clock
	std::rand(); // If using Visual Studio, discard first random value

	Monster m{ MonsterGenerator::generateMonster() };
	m.print();

	return 0;
}