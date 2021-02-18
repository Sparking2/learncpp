#include <iostream>

// Question #1
//int readNumber() {
//	std::cout << "Please enter a number: ";
//	int x{};
//	std::cin >> x;
//	return x;
//}
//
//void writeAnswer(int x) {
//	std::cout << "The sum is: " << x;
//}
//
//int main() {
//
//	int x{ readNumber() };
//	x = x + readNumber();
//	writeAnswer(x);
//
//	return 0;
//}

// Question 2
//int readNumber()
//{
//	std::cout << "Please enter a number:";
//	int x{};
//	std::cin >> x;
//	return x;
//}
//
//void writeAnswer(int x)
//{
//	std::cout << "The quotient is:" << x;
//}
//
//int main()
//{
//	int x{ readNumber() };
//	int y{ readNumber() };
//	writeAnswer(x / y);
//
//	return 0;
//}

// Question 3
void d() {
	// here
}

void c() {
}

void b() {
	c();
	d();
}

void a() {
	b();
}

int main() {
	a();

	return 0;
}