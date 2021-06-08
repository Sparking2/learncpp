#include <iostream>
#include <math.h>

using namespace std;
#define PI 3.14159
const double areaThreshold = 24;

class Circle {
private:
	double radius; // radius of the circle
public:
	double getArea() const; // returns the area of the circle
	void setRadius(double rad) {
		radius = rad;
	}
};

double Circle::getArea() const {
	int power = 2;
	return pow(radius, power) * PI;
}

int Ch_9_2_Question2() {
	Circle myCircle;
	myCircle.setRadius(6);
	if (myCircle.getArea() > areaThreshold) {
		std::cout << "That's a big circle!!\n";
	}
	else {
		std::cout << "That's a small circle!\n";
	}

	return 0;
}