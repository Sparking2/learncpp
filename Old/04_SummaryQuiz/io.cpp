#include <iostream>

int readNumber()
{
    int x{};
    std::cout << "Write an integer: ";
    std::cin >> x;
    return x;
}

void writeAnswer(int result)
{
    std::cout << "The answer is: " << result << '\n';
}