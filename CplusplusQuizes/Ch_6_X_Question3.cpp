//Complete the following program by writing the passOrFail() function,
//which should return true for the first 3 calls, and false thereafter.

//#include <iostream>
//
//int main()
//{
//	std::cout << "User #1: " << (passOrFail() ? "Pass" : "Fail") << '\n';
//	std::cout << "User #2: " << (passOrFail() ? "Pass" : "Fail") << '\n';
//	std::cout << "User #3: " << (passOrFail() ? "Pass" : "Fail") << '\n';
//	std::cout << "User #4: " << (passOrFail() ? "Pass" : "Fail") << '\n';
//	std::cout << "User #5: " << (passOrFail() ? "Pass" : "Fail") << '\n';
//
//	return 0;
//}

#include <iostream>

bool passOrFail() {
	static int counter{ 0 };
	return (++counter <= 3);

	if (counter < 3) {
		++counter;
		return true;
	}

	return false;
}

int Ch_6_X_Question3() {
	std::cout << "User #1: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #2: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #3: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #4: " << (passOrFail() ? "Pass" : "Fail") << '\n';
	std::cout << "User #5: " << (passOrFail() ? "Pass" : "Fail") << '\n';

	return 0;
}