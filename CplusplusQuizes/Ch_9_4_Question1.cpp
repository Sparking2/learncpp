//Question #1
//Manually show how selection sort works on the following array: { 30, 60, 20, 50, 40, 10 }. 
//Show the array after each swap that takes place.

#include <iostream>
#include <iterator>
#include <utility>

int Ch_9_4_Question1()
{
	int myArray[]{ 30,60,20,50,40,10 };

	for (int i{ 0 }; i < std::size(myArray) - 1; ++i) {

		int smallestIndex{ i };

		for (int j{ i + 1 }; j < std::size(myArray); ++j) {
			if (myArray[smallestIndex] > myArray[j]) {
				smallestIndex = j;
			}
		}
		std::swap(myArray[i], myArray[smallestIndex]);
	}

	for (int i{ 0 }; i < std::size(myArray); ++i)
	{
		std::cout << myArray[i] << " ";
	}

	std::cout << "\n";

	return 0;
}