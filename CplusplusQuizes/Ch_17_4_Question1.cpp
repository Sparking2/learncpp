#include <iostream>

class Fruit {
private:
    std::string m_name{};
    std::string m_color{};

public:
    Fruit(const std::string name, const std::string color)
        : m_name{ name }, m_color{ color }
    {}

    std::string getName() const {
        return m_name;
    }

    std::string getColor() const {
        return m_color;
    }

};

class Apple : Fruit {
private:
    double m_fiber{};

public:
    Apple(const std::string name, const std::string color, const double fiber)
        : Fruit{ name, color }, m_fiber{ fiber }
    {}

    friend std::ostream& operator<< (std::ostream& out, const Apple& myApple) {
        out << "Apple " << "(" << myApple.getName() << ", " << myApple.getColor() << ", " << myApple.m_fiber << ")\n";
        return out;
    }
};

class Banana : Fruit {

public:
    Banana(const std::string name, const std::string color)
        : Fruit{ name,color }
    {}

    friend std::ostream& operator<< (std::ostream& out, const Banana& myBanana) {
        out << "Banana " << "(" << myBanana.getName() << ", " << myBanana.getColor() << ")\n";
        return out;
    }
};

int main()
{
    const Apple a{ "Red delicious", "red", 4.2 };
    std::cout << a << '\n';

    const Banana b{ "Cavendish", "yellow" };
    std::cout << b << '\n';

    return 0;
}