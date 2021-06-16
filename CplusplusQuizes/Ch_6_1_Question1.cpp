// local_variables_quiz_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int getNumber() {
    int x{};
    std::cin >> x;
    return x;
}

int Ch_6_1_Question1()
{
    std::cout << "Enter an integer: ";
    int small{ getNumber() };
    std::cout << "Enter a larger integer : ";
    int large{ getNumber() };
    {
        if (small > large) {
            std::cout << "Swapping the values\n";
            int x{ large };
            large = small;
            small = x;
        }// x dies here

    }
    std::cout << "The smaller value is " << small << "\n";
    std::cout << "The larger value is " << large << "\n";

    return 0;
} // large and small die here