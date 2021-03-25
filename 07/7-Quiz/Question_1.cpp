// Take the program below and modify it so that the ball falls for as many seconds as needed until it reaches the ground.

#include <iostream>
#include "constants.h"

double calculateHeight(double initialHeight, int seconds)
{
	double distanceFallen = myConstants::gravity * seconds * seconds / 2;
	double heightNow = initialHeight - distanceFallen;

	// Check whether we've gone under the ground
	// If so, set the height to ground-level
	if (heightNow < 0.0)
		return 0.0;
	else
		return heightNow;
}

bool calculateAndPrintHeight(double initialHeight, int time)
{
	double currentHeight = calculateHeight(initialHeight, time);
	std::cout << "At " << time << " seconds, the ball is at height: " << currentHeight << "\n";
	return currentHeight <= 0.0;
}

int Question_1()
{
	using namespace std;
	cout << "Enter the initial height of the tower in meters: ";
	double initialHeight;
	cin >> initialHeight;

	int seconds = 0;
	bool hitGround = false;

	do
	{
		hitGround = calculateAndPrintHeight(initialHeight, seconds++);
	} while (!hitGround);

	return 0;
}