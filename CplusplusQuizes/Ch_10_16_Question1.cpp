//We’re going to write a little game with square numbers(numbers which can be created by multiplying an integer with itself(1, 4, 9, 16, 25, …)).
//Ask the user to input 2 numbers, the first is the square root of the number to start at,
//the second is the amount of numbers to generate.Generate a random integer from 2 to 4, 
//and square numbers in the range that was chosen by the user.
//
//Multiply each square number by the random number.You can assume that the user enters valid numbers.
//
//The user has to calculate which numbers have been generated.
//The program checks if the user guessed correctlyand removes the guessed number from the list.
//If the user guessed wrong, the game is over and the program prints the number that was closest to the user’s final guess,
//but only if the final guess was not off by more than 4.

#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <cmath>

int generateRandom() {
	std::mt19937 gen(time(0));
	std::uniform_int_distribution<> distrib(2, 4);
	return distrib(gen);
}

int findClosestNumber(const std::vector<int>& list, int guess) {
	return *std::min_element(list.begin(), list.end(), [=](int a, int b) {
		return (std::abs(a - guess) < std::abs(b - guess));
		});
}

int Ch_10_16_Question1()
{
	int random{ generateRandom() };

	std::cout << "Start where? ";
	int start{};
	std::cin >> start;

	std::cout << "\n How many? ";
	int ammount{};
	std::cin >> ammount;

	std::vector<int> list;

	list.reserve(ammount);

	for (int i{ start }; i < start + ammount; i++) {
		list.push_back(i * i);
	}

	for (int& numb : list) {
		numb = numb * random;
	}

	std::cout << '\n';
	for (int numb : list) {
		std::cout << numb << " ";
	}

	std::cout << "\nI generated " << ammount << " square numbers. Do you know what each number is after multiplying it by " << random << "?\n";

	do
	{
		// Loop
		int guess{};
		std::cout << "\nCan you guess the numbers?: ";
		std::cin >> guess;

		auto found{ std::find(list.begin(), list.end(), guess) };

		if (found == list.end()) {
			std::cout << "Ups it's wrong";
			int closest{ findClosestNumber(list, guess) };
			if (std::abs(closest - guess) <= 4) {
				std::cout << "Try " << closest << " next time. \n";
			}
			else {
				std::cout << '\n';
			}
			break;
		}
		else {
			list.erase(found);
		}

		std::cout << '\n';
		for (int numb : list) {
			std::cout << numb << " ";
		}

	} while (!list.empty());

	if (list.empty()) {
		std::cout << "You win";
	}
	else {

	}


	return 0;
}