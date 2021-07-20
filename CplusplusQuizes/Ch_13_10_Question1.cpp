//Question #1
//
//Write a class that holds a string.
//Overload operator() to return the substring that starts at the index of the first parameter.
//The length of the substring should be defined by the second parameter.
//Hint : You can use array indices to access individual chars within the std::string
//Hint : You can use operator+= to append something to a string

#include <string>
#include <iostream>

class Mystring {
private:
	std::string m_string{};
public:
	Mystring(std::string x) : m_string{x}
	{}

	std::string operator()(int start, int size);
};

std::string Mystring::operator()(int start, int size)
{
	std::string substring{};
	int end{ start + size };

	for (int i = start; i < end; i++)
	{
		substring += m_string[i];
	}

	return substring;
}

int Ch_13_10_Question1()
{
	Mystring string{ "Hello, world!" };
	std::cout << string(7, 5) << '\n'; // start at index 7 and return 5 characters

	return 0;
}