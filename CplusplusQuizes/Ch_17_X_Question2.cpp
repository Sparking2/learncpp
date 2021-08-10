#include <iostream>

class Fruit {
protected:
    std::string m_name{};
    std::string m_color{};

public:
    Fruit(std::string name, std::string color)
        : m_name{ name }, m_color{ color }
    {}

    std::string getName() { return m_name; }
    std::string getColor() { return m_color; }
};

class Apple : public Fruit {
private:
public:
    Apple(std::string color = "red")
        : Fruit{ "Apple", color }
    {}
};

class Banana : public Fruit {
private:
public:
    Banana(std::string color = "yellow")
        : Fruit("Banana", color)
    {}
};

class GrannySmith : public Fruit {
private:
public:
    GrannySmith(std::string name = "granny smith", std::string color = "green")
        : Fruit{ name,color }
    {}
};

int Ch_17_X_Question2() {
    Apple a{ "red" };
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}