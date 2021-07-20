#include <cassert> // for assert()
#include <initializer_list> // for std::initializer_list
#include <iostream>

class IntArrayD
{
private:
	int m_length{};
	int* m_data{};

public:
	IntArrayD() = default;

	IntArrayD(int length) :
		m_length{ length },
		m_data{ new int[length] {} }
	{

	}

	IntArrayD(std::initializer_list<int> list) : // allow IntArray to be initialized via list initialization
		IntArrayD(static_cast<int>(list.size())) // use delegating constructor to set up initial array
	{
		// Now initialize our array from the list
		int count{ 0 };
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}
	}

	~IntArrayD()
	{
		delete[] m_data;
		// we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
	}

	IntArrayD(const IntArrayD&) = delete; // to avoid shallow copies
	IntArrayD& operator=(const IntArrayD& list) = delete; // to avoid shallow copies

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	int getLength() const { return m_length; }
};

int Question1()
{
	IntArrayD array{ 5, 4, 3, 2, 1 }; // initializer list
	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	//array = { 1, 3, 5, 7, 9, 11 };

	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	return 0;
}

//This should print :
//
//5 4 3 2 1
//1 3 5 7 9 11