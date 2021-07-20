#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cmath>

class FixedPoint2 {
private:
	std::int16_t m_nonFractional{};
	std::int8_t m_fractional{};

public:
	FixedPoint2(std::int16_t non, std::int8_t fr)
		: m_nonFractional{ non }, m_fractional{ fr }
	{
		bool negative = non < 0 || fr < 0 ? true : false;
		if (negative) {
			m_nonFractional = m_nonFractional > 0 ? -m_nonFractional : m_nonFractional;
			m_fractional = m_fractional > 0 ? -m_fractional : m_fractional;
		}
	}
	FixedPoint2(double d) {
		m_nonFractional = static_cast<std::int16_t>(std::round(d * 100) / 100);
		m_fractional = static_cast<std::int8_t>(std::round(d * 100) - m_nonFractional * 100);
	}

	operator double() const {
		return m_nonFractional + static_cast<double>(m_fractional) / 100.0;
	}
	friend std::ostream& operator<< (std::ostream& out, FixedPoint2& point);
};

std::ostream& operator<<(std::ostream& out, FixedPoint2& point)
{
	double num{ point.m_nonFractional + (static_cast<double>(point.m_fractional) / 100) };
	out << num;
	return out;
}

void testAddition() {
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 }) << '\n'; // both positive, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 }) << '\n'; // both positive, with decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }) << '\n'; // both negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }) << '\n'; // both negative, with decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 }) << '\n'; // second negative, no decimal overflow
	std::cout << (FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 }) << '\n'; // second negative, possible decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 }) << '\n'; // first negative, no decimal overflow
	std::cout << (FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 }) << '\n'; // first negative, possible decimal overflow
}

int Question4() {

#pragma region pt1
	//FixedPoint2 a{ 34,56 };
	//std::cout << a << '\n';

	//FixedPoint2 b{ -2,8 };
	//std::cout << b << '\n';

	//FixedPoint2 c{ 2,-8 };
	//std::cout << c << '\n';

	//FixedPoint2 d{ -2,-8 };
	//std::cout << d << '\n';

	//FixedPoint2 e{ 0,-5 };
	//std::cout << e << '\n';

	//std::cout << static_cast<double>(e) << '\n';
#pragma endregion

#pragma region pt2
	//// Handle cases where the argument is representable directly
	//FixedPoint2 a{ 0.01 };
	//std::cout << a << '\n';

	//FixedPoint2 b{ -0.01 };
	//std::cout << b << '\n';

	//// Handle cases where the argument has some rounding error
	//FixedPoint2 c{ 5.01 }; // stored as 5.0099999... so we'll need to round this
	//std::cout << c << '\n';

	//FixedPoint2 d{ -5.01 }; // stored as -5.0099999... so we'll need to round this
	//std::cout << d << '\n';

	//// Handle case where the argument's decimal rounds to 100 (need to increase base by 1)
	//FixedPoint2 e{ 106.9978 }; // should be stored with base 107 and decimal 0
	//std::cout << e << '\n';
#pragma endregion

	testAddition();

	FixedPoint2 a{ -0.48 };
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // enter 5.678
	//std::cin >> a;

	std::cout << "You entered: " << a << '\n';

	return 0;

	return 0;
}