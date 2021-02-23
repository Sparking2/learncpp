#include <iostream>

//bool isPrime(int x) {
//	if (x == 2)
//		return true;
//	else if (x == 3)
//		return true;
//	else if (x == 5)
//		return true;
//	else if (x == 7)
//		return true;
//	else
//		return false;
//}
//
//int main() {
//
//	std::cout << "Please enter a number: ";
//	int x{};
//	std::cin >> x;
//
//	if (isPrime(x)) {
//		std::cout << "The number is prime.";
//	}
//	else {
//		std::cout << "The numbner isn't prime.";
//	}
//
//	return 0;
//}

bool isAllowedToTakeFunRide()
{
    std::cout << "How tall are you? (cm)\n";

    double height{};
    std::cin >> height;

    return (height > 140.0);
}

int main()
{
    if (isAllowedToTakeFunRide())
        std::cout << "Have fun!\n";
    else
        std::cout << "Sorry, you're too short.\n";

    return 0;
}