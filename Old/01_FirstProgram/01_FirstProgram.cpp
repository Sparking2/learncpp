//#include <iostream>
//
//int main()
//{
//	std::cout << "Enter an integer: ";
//
//	int num{ 0 };
//	std::cin >> num;
//
//	std::cout << "Double " << num << " is: " << num * 2 << '\n';
//	std::cout << "Triple " << num << " is: " << num * 3 << '\n';
//	return 0;
//}

#include <iostream>

int main()
{
	std::cout << "Enter an integer: ";
	int numOne{ 0 };
	std::cin >> numOne;

	std::cout << "Enter another integer: ";
	int numTwo{ 0 };
	std::cin >> numTwo;

	std::cout << numOne << " + " << numTwo << " is " << numOne + numTwo << ".\n";
	std::cout << numOne << " - " << numTwo << " is " << numOne - numTwo << ".\n";
	return 0;
}