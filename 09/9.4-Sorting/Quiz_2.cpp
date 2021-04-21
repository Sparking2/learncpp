//Question #2
//Rewrite the selection sort code above to sort in descending order(largest numbers first).
//Although this may seem complex, it is actually surprisingly simple.

#include <iostream>
#include <iterator>
#include <utility>

int Quiz_2()
{
	int myArray[]{ 30,60,20,50,40,10 };

	for (int i{ 0 }; i < std::size(myArray) - 1; ++i) {

		int biggerIndex{ i };

		for (int j{ i + 1 }; j < std::size(myArray); ++j) {
			if (myArray[biggerIndex] < myArray[j]) {
				biggerIndex = j;
			}
		}
		std::swap(myArray[i], myArray[biggerIndex]);
	}

	for (int i{ 0 }; i < std::size(myArray); ++i)
	{
		std::cout << myArray[i] << " ";
	}

	std::cout << "\n";

	return 0;
}