//Question #2
//
//Write a program that prints out the letters a through z along with their ASCII codes.
//Hint: to print characters as integers, you have to use a static_cast.


#include <iostream>

int Ch_7_7_Question2() {

	int currentLetter = 97;

	while (currentLetter <= 122)
	{
		std::cout << static_cast<char>(currentLetter) << ' ';
		++currentLetter;
	}
	std::cout << '\n';

	return 0;
}