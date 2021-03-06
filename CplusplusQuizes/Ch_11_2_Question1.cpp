// 11.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//a) Create a class called IntPair that holds two integers.This class should have two member variables to hold the integers.
//You should also create two member functions :
//one named �set� that will let you assign values to the integers,
//and one named �print� that will print the values of the variables.

#include <iostream>

class IntPair {
public:
	int m_x;
	int m_y;

	void set(int x, int y) {
		m_x = x;
		m_y = y;
	};

	void print() {
		std::cout << "Pair(" << m_x << ", " << m_y << ")" << '\n';
	};
};

int Ch_11_2_Question1()
{
	IntPair p1;
	p1.set(1, 1); // set p1 values to (1, 1)

	IntPair p2{ 2, 2 }; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	return 0;
}
