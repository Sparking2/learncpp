//Question #1
//
//Write a class named Ball.
//Ball should have two private member variables with default values : m_color(�black�) and m_radius(10.0).
//Ball should provide constructors to set only m_color, set only m_radius, set both, or set neither value.
//For this quiz question, do not use default parameters for your constructors.
//Also write a function to print out the colorand radius of the ball.
//The following sample program should compile :

#include <iostream>

class Ball {

private:
	std::string m_color{};
	double m_radius{};

public:
	Ball(double radius) {
		m_radius = radius;
		m_color = "black";
	}
	Ball(std::string color = "black", double radius = 10.0) {
		m_color = color;
		m_radius = radius;
	}

	void print() {
		std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
};

int Ch_11_5_Question1()
{
	Ball def{};
	def.print();

	Ball blue{ "blue" };
	blue.print();

	Ball twenty{ 20.0 };
	twenty.print();

	Ball blueTwenty{ "blue", 20.0 };
	blueTwenty.print();

	return 0;
}