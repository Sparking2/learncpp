// Question_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "constants.h"

float getHeight() {
	std::cout << "Enter the height of the tower in meters: ";
	float h{};
	std::cin >> h;
	return h;
}

double distanceFallen(int seconds) {

	double doubled_seconds = static_cast<double>(seconds);

	return (gravity * doubled_seconds * doubled_seconds / 2);
}

void calculateResult(double distance, float height, int seconds) {

	double result = height - distance;

	if (result <= 0) {
		std::cout << "At " << seconds << " seconds, the ball is in the ground \n";
	}
	else {
		std::cout << "At " << seconds << " the ball is at height: " << result << "\n";
	}

}

int main()
{
	float height{ getHeight() };
	calculateResult(distanceFallen(0), height, 0);
	calculateResult(distanceFallen(1), height, 1);
	calculateResult(distanceFallen(2), height, 2);
	calculateResult(distanceFallen(3), height, 3);
	calculateResult(distanceFallen(4), height, 4);
	calculateResult(distanceFallen(5), height, 5);
}

