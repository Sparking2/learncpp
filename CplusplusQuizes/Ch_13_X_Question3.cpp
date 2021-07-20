#include <iostream>
#include <cassert>

class IntArray {
private:
	int m_size{ 0 };
	int* m_array{ nullptr };

public:
	IntArray(int size) : m_size{ size } {
		assert(size > 0 && "IntArray size should be a positive integer!");

		m_array = new int[m_size] {};
	};
	IntArray(const IntArray& array) : m_size{ array.m_size } {
		m_array = new int[m_size];

		for (int count{ 0 }; count < array.m_size; ++count) {
			m_array[count] = array.m_array[count];
		}
	}
	~IntArray() {
		delete[] m_array;
	};

	int& operator[](int index);
	IntArray& operator= (const IntArray& array);
	friend std::ostream& operator<<(std::ostream& out, IntArray& array);
};

int& IntArray::operator[](int index)
{
	assert(index >= 0);
	assert(index < m_size);
	return m_array[index];
}
std::ostream& operator<<(std::ostream& out, IntArray& iArray)
{
	for (int i = 0; i < iArray.m_size; i++)
	{
		out << iArray[i] << " ";
	}
	return out;
}
IntArray& IntArray::operator=(const IntArray& array)
{
	if (this == &array)
		return *this;

	delete[] m_array;

	m_size = array.m_size;
	m_array = new int[m_size];

	for (int count{ 0 }; count < array.m_size; ++count)
		m_array[count] = array.m_array[count];

	return *this;
}

IntArray fillArray() {
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int Question3() {
	IntArray a{ fillArray() };
	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	std::cout << b << '\n';

	return 0;
}