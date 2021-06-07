// 10.12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int factorial(int n) {

	if (n <= 1)
		return 1;

	return n * factorial(n - 1);
}

int sumNumbers(int x) {
	if (x < 10) {
		return x;
	}
	else {
		return sumNumbers(x / 10) + x % 10;
	}
}

void printBinary(int x) {
	if (x == 0)
		return;

	printBinary(x / 2);

	std::cout << x % 2;
}

int Ch_10_12_Question1()
{
	std::cout << factorial(7) << '\n';
	std::cout << sumNumbers(93427) << '\n';

	int x;
	std::cout << "Enter a positive integer: ";
	std::cin >> x;

	printBinary(x);

	return 0;
}