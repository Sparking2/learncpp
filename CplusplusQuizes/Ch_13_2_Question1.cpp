//Question #1
//
//a) Write a class named Fraction that has a integer numeratorand denominator member.
//Write a print() function that prints out the fraction.

#include <iostream>

class Fraction13 {
private:
	int m_numerator{};
	int m_denominator{};

public:
	Fraction13(int n, int d) : m_numerator{ n }, m_denominator{ d }
	{}

	void print() {
		std::cout << m_numerator << "/" << m_denominator << '\n';
	}

	friend Fraction13 operator* (const Fraction13& f1, const Fraction13& f2);
	friend Fraction13 operator* (Fraction13& f, int i);
	friend Fraction13 operator* (int i, Fraction13& f);
};

Fraction13 operator*(const Fraction13& f1, const Fraction13& f2) {
	int numerator{ f1.m_numerator * f2.m_numerator };
	int denominator{ f1.m_denominator * f2.m_denominator };

	return { numerator, denominator };
}

Fraction13 operator*(Fraction13& f, int i)
{
	int numerator{ f.m_numerator * i };
	return { numerator, f.m_denominator };
}

Fraction13 operator*(int i, Fraction13& f)
{
	return (f * i);
}

int Ch_13_2_Question1()
{
	Fraction13 f1{ 2, 5 };
	f1.print();

	Fraction13 f2{ 3, 8 };
	f2.print();

	Fraction13 f3{ f1 * f2 };
	f3.print();

	Fraction13 f4{ f1 * 2 };
	f4.print();

	Fraction13 f5{ 2 * f2 };
	f5.print();

	Fraction13 f6{ Fraction13{1, 2} *Fraction13{2, 3} *Fraction13{3, 4} };
	f6.print();

	return 0;
}