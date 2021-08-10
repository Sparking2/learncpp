#include <array>
#include <iostream>

#include "dog.h"
#include "cat.h"

int main() {
    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };

    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };

    const std::array<const Animal*, 6>animals{ &fred,&misty,&zeke,&garbo,&pooky,&truffle };

    for (const auto animal : animals) {
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    }

    return 0;
}