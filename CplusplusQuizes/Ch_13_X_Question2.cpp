#include <cstdint>
#include <iostream>

class Average {
private:
	std::int_least32_t m_sum{};
	std::int_least8_t m_numers{};

public:
	Average() {};

	Average& operator+=(int numb);
	friend std::ostream& operator<< (std::ostream& out, const Average& avg);
	//friend void operator+=(int num);
};

Average& Average::operator+=(int numb) {
	this->m_sum += numb;
	this->m_numers++;

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Average& avg)
{
	out << static_cast<double>(avg.m_sum) / static_cast<double>(avg.m_numers) << '\n';
	return out;
}

int Question2() {

	Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4;

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}
