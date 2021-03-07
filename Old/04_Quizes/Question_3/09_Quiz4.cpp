// 09_Quiz4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

double getNumber() {
	std::cout << "Enter a double value: ";
	double number{};
	std::cin >> number;
	return number;
}

char getAritmeticOperation() {
	std::cout << "Enter one of the following: +, -, *, or /: ";
	char operation;
	std::cin >> operation;
	return operation;
}

void calculateOperation(double num1, double num2, char operation) {
	if (operation == '+') {
		std::cout << num1 << " + " << num2 << " is " << num1 + num2;
	}
	else if (operation == '-') {
		std::cout << num1 << " - " << num2 << " is " << num1 - num2;
	}
	else if (operation == '*') {
		std::cout << num1 << " * " << num2 << " is " << num1 * num2;
	}
	else if (operation == '/') {
		std::cout << num1 << " / " << num2 << " is " << num1 / num2;
	}
}

int main()
{
	double num1{ getNumber() };

	double num2{ getNumber() };

	char operation{ getAritmeticOperation() };

	calculateOperation(num1, num2, operation);

	//calculateOperation(getNumber(), getNumber(), getAritmeticOperation());

	return 0;
}
