//Question #4
//
//Now make the numbers print like this:
//        1
//      2 1
//    3 2 1
//  4 3 2 1
//5 4 3 2 1

#include <iostream>

int Ch_7_7_Question4()
{
	int currentNumber = 1;

	int outer{ 1 };
	while (outer <= 5)
	{
		int inner{ 5 };
		while (inner >= 1)
		{
			if (inner <= outer) {
				std::cout << ' ' << inner << ' ';
			}
			else {
				std::cout << ' ' << ' ' << ' ';
			}
			--inner;
		}
		std::cout << '\n';
		++outer;
	}
	return 0;
}