//Question #3
//
//Now let’s try something a little more complex.
//Let’s write a class that implements a simple stack from scratch.
//Review lesson 10.10 --The stack and the heap if you need a refresher on what a stack is.
//The class should be named Stack, and should contain :
//*A private fixed array of integers of length 10.
//* A private integer to keep track of the size of the stack.
//* A public member function named reset() that sets the size to 0.
//* A public member function named push() that pushes a value on the stack.push() should return false if the array is already full, and true otherwise.
//* A public member function named pop() that pops a value off the stackand returns it.If there are no values on the stack, the code should exit via an assert.
//* A public member function named print() that prints all the values in the stack.
//
//Make sure the following program executes correctly :
//
//()
//(5 3 8)
//(5 3)
//()

#include <iostream>
#include <cassert>

class Stack {
private:
	int m_array[10]{};
	int m_arraySize{};

public:
	void reset() {
		m_arraySize = 0;
	}
	bool push(int num) {
		if (m_arraySize >= 10)
			return false;

		m_array[m_arraySize] = num;
		m_arraySize += 1;

		return true;
	}
	int pop() {
		assert(m_arraySize > 0);
		int value = m_array[m_arraySize];
		m_arraySize -= 1;
		return value;
	}
	void print() {
		std::cout << "\n( ";
		for (int i{ 0 }; i < m_arraySize; ++i) {
			std::cout << m_array[i] << " ";
		}
		std::cout << ")\n";
	}
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}