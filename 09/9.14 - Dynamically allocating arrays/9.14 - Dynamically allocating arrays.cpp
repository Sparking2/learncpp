//Question #1
//
//Write a program that :
//*Asks the user how many names they wish to enter.
//* Dynamically allocates a std::string array.
//* Asks the user to enter each name.
//* Calls std::sort to sort the names(See 9.4 --Sorting an array using selection sort and 9.11 --Pointer arithmetic and array indexing)
//* Prints the sorted list of names.
//
//std::string supports comparing strings via the comparison operators <and >.You don’t need to implement string comparison by hand.
//
//Your output should match this:
//
//How many names would you like to enter ? 5
//Enter name #1: Jason
//Enter name #2: Mark
//Enter name #3: Alex
//Enter name #4: Chris
//Enter name #5: John
//
//Here is your sorted list :
//Name #1: Alex
//Name #2: Chris
//Name #3: Jason
//Name #4: John
//Name #5: Mark

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::cout << "How many names you wish to enter?: ";
	std::size_t nameCount{};
	std::cin >> nameCount;

	std::string* nameArray{ new std::string[nameCount] };

	for (int i = 0; i < nameCount; i++)
	{
		std::cout << "Write a name: ";
		std::string name{};
		std::cin >> name;
		nameArray[i] = name;
	}

	// std::sort(&nameArray[0], &nameArray[nameCount]);
	std::sort(nameArray, nameArray + nameCount);

	for (int i = 0; i < nameCount; i++) {
		std::cout << nameArray[i] << '\n';
	}

	delete[] nameArray;

	return 0;
}

// THeir solution
//#include <algorithm> // std::sort
//#include <cstddef> // std::size_t
//#include <iostream>
//#include <limits> // std::numeric_limits
//#include <string>
//
//std::size_t getNameCount()
//{
//	std::cout << "How many names would you like to enter? ";
//	std::size_t length{};
//	std::cin >> length;
//
//	return length;
//}
//
//// Asks user to enter all the names
//void getNames(std::string* names, std::size_t length)
//{
//	// Ignore the line feed that was left by std::cin.
//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//	for (std::size_t i{ 0 }; i < length; ++i)
//	{
//		std::cout << "Enter name #" << i + 1 << ": ";
//		std::getline(std::cin, names[i]);
//	}
//}
//
//// Prints the sorted names
//void printNames(std::string* names, std::size_t length)
//{
//	std::cout << "\nHere is your sorted list:\n";
//
//	for (std::size_t i{ 0 }; i < length; ++i)
//		std::cout << "Name #" << i + 1 << ": " << names[i] << '\n';
//}
//
//int main()
//{
//	std::size_t length{ getNameCount() };
//
//	// Allocate an array to hold the names
//	auto* names{ new std::string[length]{} };
//
//	getNames(names, length);
//
//	// Sort the array
//	std::sort(names, names + length);
//
//	printNames(names, length);
//
//	// don't forget to use array delete
//	delete[] names;
//	// we don't need to set names to nullptr/0 here because it's going to go out
//	// of scope immediately after this anyway.
//
//	return 0;
//}


