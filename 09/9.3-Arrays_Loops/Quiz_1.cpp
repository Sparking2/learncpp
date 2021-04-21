//Question #1
//Print the following array to the screen using a loop :
//constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
//Hint: You can use std::size(as of C++17) or the sizeof() trick(prior to C++17) to determine the array length.

#include <iostream>
#include <iterator>

int Quiz_1() {
	constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

	for (int i{ 0 }; i < std::size(array); i++)
	{
		std::cout << " " << array[i] << " ";
	}

	std::cout << "\n";

	return 0;
}