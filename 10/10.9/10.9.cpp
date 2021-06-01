// 10.9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>

using ArithmeticFunction = std::function<int(int, int)>;

int getInteger() {
	std::cout << "Enter an Integer: ";
	int x{};
	std::cin >> x;
	return x;
}

char getOperator() {
	char op{};

	do
	{
		std::cout << "Enter an operator: ";
		std::cin >> op;
	} while (op != '+' && op != '-' && op != '*' && op != '/');

	return op;
}

int add(int x, int y) {
	return x + y;
}

int substract(int x, int y) {
	return x - y;
}

int multiply(int x, int y) {
	return x * y;
}

int divide(int x, int y) {
	return x / y;
}

ArithmeticFunction getArithmeticFunction(char op) {
	switch (op) {
	default:
	case '+': return &add;
	case '-': return &substract;
	case '*': return &multiply;
	case '/': return &divide;
	}
}

int main()
{
	int x{ getInteger() };
	char operation{ getOperator() };
	int y{ getInteger() };

	ArithmeticFunction fn{ getArithmeticFunction(operation) };

	std::cout << x << operation << y << '\n';
	std::cout << fn(x, y) << '\n';

	return 0;
}

