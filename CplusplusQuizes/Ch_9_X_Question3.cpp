//Question #3
//
//Write your own function to swap the value of two integer variables. Write a main() function to test it.
//
//Use reference parameters
//void swap(int& a, int& b)

#include <iostream>

void swap(int& a, int& b) {
	int c{ b };
	b = a;
	a = c;
}

int Ch_9_X_Question3() {

	int x{ 5 };
	int y{ 9 };

	std::cout << "x: " << x << ", y: " << y << "\n";

	swap(x, y);

	std::cout << "x: " << x << ", y: " << y << "\n";

	if (x == 9 && y == 5)
		std::cout << "It works!\n";
	else
		std::cout << "It's broken!\n";

	return 0;
}