//Question #4
//Add two optimizations to the bubble sort algorithm you wrote in the previous quiz question :
//Notice how with each iteration of bubble sort, the biggest number remaining gets bubbled to the end of the array.
//After the first iteration, the last array element is sorted.
//After the second iteration, the second to last array element is sorted too.
//And so on… With each iteration, we don’t need to recheck elements that we know are already sorted.
//Change your loop to not re - check elements that are already sorted.
//If we go through an entire iteration without doing a swap, then we know the array must already be sorted.
//Implement a check to determine whether any swaps were made this iteration, and if not, terminate the loop early.
//If the loop was terminated early, print on which iteration the sort ended early.
//Your output should match this :
//
//	Early termination on iteration 6
//	1 2 3 4 5 6 7 8 9

#include <iostream>
#include <iterator>
#include <utility>

int Ch_9_4_Question4() {
	int myArray[]{ 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	constexpr std::size_t length{ std::size(myArray) };

	for (std::size_t i{ 0 }; i < length - 1; ++i) {

		std::size_t endOfArrayIndex{ length - i };

		bool swaped{ false };

		for (std::size_t currentIndex{ 0 }; currentIndex < endOfArrayIndex - 1; ++currentIndex) {
			if (myArray[currentIndex] > myArray[currentIndex + 1]) {
				std::swap(myArray[currentIndex], myArray[currentIndex + 1]);
				swaped = true;
			}
		}

		if (!swaped) {
			std::cout << "Early termination on iteration: " << i - 1 << '\n';
			break;
		}
	}

	for (int i{ 0 }; i < std::size(myArray); ++i)
	{
		std::cout << myArray[i] << " ";
	}
	std::cout << "\n";

	return 0;
}