#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <string_view>


int generateRandomNumber(int min, int max) {
    static constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

class Creature {
protected:
    const std::string m_name;
    char m_symbol;
    int m_health;
    int m_damage;
    int m_gold;

public:
    // Constructor    
    Creature(const std::string& name, char symbol, int health, int dmg, int gold)
        : m_name{ name },
        m_symbol{ symbol },
        m_health{ health },
        m_damage{ dmg },
        m_gold{ gold }
    {}

    // Geters
    const std::string getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int getHealth() const { return m_health; }
    int getDamage() const { return m_damage; }
    int getGold() const { return m_gold; }

    // Other Functions
    void reduceHealth(int dmg) {
        m_health -= dmg;
    }
    bool isDead() {
        return m_health <= 0;
    }
    void addGold(int gold) {
        m_gold += gold;
    }
};

class Player : public Creature {
private:
    int m_level{ 1 };
public:
    // Constructor
    Player(std::string name)
        : Creature{ name, '@', 10, 1,0 }
    {}

    // Getters
    int getLevel() const {
        return m_level;
    }

    // Functions
    void levelUp() {
        ++m_level;
        ++m_damage;
    }
    bool hasWon() {
        return m_level >= 20;
    }
};

class Monster : public Creature {
public:
    enum class Type {
        dragon,
        orc,
        slime,
        max_types
    };

private:
    // static const Creature& getDefaultCreature(Type type) {
    //     static std::array<Creature, static_cast<std::size_t>(Type::max_types)> monsterData{
    //         {
    //             {"dragon",'D',20,4,100},
    //             {"orc",'o',4,2,25},
    //             {"slime",'s',1,1,10}
    //         }
    //     };
    //     return monsterData[static_cast<std::size_t>(type)];
    //     //return monsterData.at(static_cast<std::size_t>(type));
    // }

    // Creature& getCreature(Type type) {
    //     std::array<Creature, static_cast<int>(Type::max_types)> monsterData{
    //         {
    //             {"dragon",'D',20,4,100},
    //             {"orc",'o',4,2,25},
    //             {"slime",'s',1,1,10}
    //         }
    //     };
    //     return monsterData[static_cast<int>(type)];
    // }

    Creature getCreature(Type type) {
        std::array<Creature, 3> monsterData{
            {
                {"dragon",'D',20,4,100},
                {"orc",'o',4,2,25},
                {"slime",'s',1,1,10}
            }
        };
        return monsterData.at(1);
    }

public:
    Monster(Type type)
        : Creature{ getCreature(type) }
    {}

    static Monster getRandomMonster() {
        int num{ generateRandomNumber(0, static_cast<int>(Type::max_types) - 1) };
        return Monster{ static_cast<Type>(num) };
    }
};

int main() {

    // Creature o{ "orc", 'o', 4,2,10 };
    // o.addGold(5);
    // o.reduceHealth(1);
    // std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";

    // std::cout << "Enter your name: ";
    // std::string name{};
    // std::cin >> name;
    // Player p{ name };
    // std::cout << "Welcome " << p.getName() << ".\n";
    // std::cout << "You have " << p.getHealth() << " and are carrying " << p.getGold() << " gold.\n";

    // Monster m{ Monster::Type::orc };
    // std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();

    for (int i{ 0 }; i < 10; i++) {
        Monster m{ Monster::getRandomMonster() };
        std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
    }

    return 0;
}