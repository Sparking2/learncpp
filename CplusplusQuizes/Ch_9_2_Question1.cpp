// 9.2-Arrays.cpp 
//

//1) Declare an array to hold the high temperature(to the nearest tenth of a degree)
//for each day of a year(assume 365 days in a year).
//Initialize the array with a value of 0.0 for each day.
//
//2) Set up an enum with the names of the following animals : chicken, dog, cat, elephant, duck, and snake.
//Put the enum in a namespace.
//Define an array with an element for each of these animals, and use an initializer list to initialize each element to hold the number of legs that animal has.
//
//Write a main function that prints the number of legs an elephant has, using the enumerator.

#include <iostream>

namespace Animals {
	enum Animals {
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,

		enum_size
	};
}

int Ch_9_2_Question1()
{
	double temperature[365]{};

	int animalArray[Animals::enum_size]{ 2,4,4,4,2,0 };

	std::cout << "An elephant has " << animalArray[Animals::elephant] << " legs.\n";

	return 0;
}