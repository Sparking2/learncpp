//A prime number is a natural number greater than 1 that is evenly divisible (with no remainder) only by 1 and itself.
//Complete the following program by writing the isPrime() function using a for loop.

#include <iostream>
#include <cassert>

bool isPrime(int x)
{
	int divisors{ 1 };
	for (int test{ 2 }; test <= x; ++test) {
		if (x % test == 0)
			++divisors;
	}
	return (divisors == 2);
}

int Ch_7_X_Question2()
{
	assert(!isPrime(0));
	assert(!isPrime(1));
	assert(isPrime(2));
	assert(isPrime(3));
	assert(!isPrime(4));
	assert(isPrime(5));
	assert(isPrime(7));
	assert(!isPrime(9));
	assert(isPrime(11));
	assert(isPrime(13));
	assert(!isPrime(15));
	assert(!isPrime(16));
	assert(isPrime(17));
	assert(isPrime(19));
	assert(isPrime(97));
	assert(!isPrime(99));
	assert(!isPrime(99));
	assert(isPrime(13417));

	std::cout << "Success!";

	return 0;
}