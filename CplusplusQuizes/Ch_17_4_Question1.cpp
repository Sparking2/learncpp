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

class Apple_old : Fruit {
private:
    double m_fiber{};

public:
    Apple_old(const std::string name, const std::string color, const double fiber)
        : Fruit{ name, color }, m_fiber{ fiber }
    {}

    friend std::ostream& operator<< (std::ostream& out, const Apple_old& myApple_old) {
        out << "Apple_old " << "(" << myApple_old.getName() << ", " << myApple_old.getColor() << ", " << myApple_old.m_fiber << ")\n";
        return out;
    }
};

class Banana_old : Fruit {

public:
    Banana_old(const std::string name, const std::string color)
        : Fruit{ name,color }
    {}

    friend std::ostream& operator<< (std::ostream& out, const Banana_old& myBanana_old) {
        out << "Banana_old " << "(" << myBanana_old.getName() << ", " << myBanana_old.getColor() << ")\n";
        return out;
    }
};

int Ch_17_4_Question1()
{
    const Apple_old a{ "Red delicious", "red", 4.2 };
    std::cout << a << '\n';

    const Banana_old b{ "Cavendish", "yellow" };
    std::cout << b << '\n';

    return 0;
}