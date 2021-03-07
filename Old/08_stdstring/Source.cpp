#include <iostream>
#include <string>

int main() {
	std::cout << "Enter your full name: ";
	std::string name{};
	std::getline(std::cin, name);

	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	int letters{ static_cast<int>(name.length()) };

	double lifeTime{ static_cast<double>(age) / static_cast<double>(letters) };

	std::cout << "you\'ve lived " << lifeTime << " years for each letter in your name";

	return 0;
}