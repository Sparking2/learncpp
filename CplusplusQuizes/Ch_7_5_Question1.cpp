// 7-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Question #1
//
//Write a function called calculate() that takes two integers and a char representing one of the following mathematical operations : +, -, *, / , or % (modulus).
//Use a switch statement to perform the appropriate mathematical operation on the integers, and return the result.
//If an invalid operator is passed into the function, the function should print an error.
//For the division operator, do an integer division.
//Hint : “operator” is a keyword, variables can’t be named “operator”.

#include <iostream>

int calculate(int x, int y, char op) {
	switch (op)
	{
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	case '%':
		return x % y;
	default:
		std::cout << "Error, invalid operator.\n";
		return -1;
	}
}

int Ch_7_5_Question1()
{
	std::cout << "Write the first number: ";
	int x{};
	std::cin >> x;

	std::cout << "Write the second number: ";
	int y{};
	std::cin >> y;

	std::cout << "Write an operator: ";
	char op{};
	std::cin >> op;

	std::cout << calculate(x, y, op);

	return 0;
}