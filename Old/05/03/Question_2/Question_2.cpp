// Question_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool isEven(int number) {
	return (number % 2) == 0;
}

int main()
{
	std::cout << "Enter an integer: ";
	int num{};
	std::cin >> num;

	if (isEven(num)) {
		std::cout << num << " is even";
	}
	else {
		std::cout << num << " is odd";
	}
}

