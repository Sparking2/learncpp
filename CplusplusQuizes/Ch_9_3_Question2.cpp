//Question #2
//
//Given the array in question 1:
//Ask the user for a number between 1 and 9. 
//If the user does not enter a number between 1 and 9, repeatedly ask for an integer value until they do.
//Once they have entered a number between 1 and 9, print the array.
//Then search the array for the value that the user enteredand print the index of that element.
//
//You can test std::cin for invalid input by using the following code :
//// if the user entered something invalid
//if (std::cin.fail())
//{
//    std::cin.clear(); // reset any error flags
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
//}

#include <iostream>
#include <iterator>

int Ch_9_3_Question2() {
	constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

	bool validOption = false;

	int userInput{};
	do
	{
		std::cout << "Enter a number between 1 and 9\n";
		std::cin >> userInput;

		if (userInput > 0 && userInput < 10) {
			validOption = true;
		}

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	} while (validOption == false);

	for (int i{ 0 }; i < std::size(array); i++)
	{
		std::cout << " " << array[i] << " ";
	}
	std::cout << "\n";

	for (int i{ 0 }; i < std::size(array); ++i)
	{
		if (array[i] == userInput) {
			std::cout << "Number in index " << i << "\n";
		}
	}

	return 0;
}