#include <iostream>

int main()
{
	std::cout << "Hello, world";
	return 0;
}

//#include <array>
//#include <iostream>
//#include <string_view>
//#include <tuple>
//#include <type_traits>
//
//namespace a::b::c
//{
//	inline constexpr std::string_view str{ "hello" };
//}
//
//template <class... T>
//std::tuple<std::size_t, std::common_type_t<T...>> sum(T... args)
//{
//	return { sizeof...(T), (args + ...) };
//}
//
//int main()
//{
//	auto [iNumbers, iSum] { sum(1, 2, 3) };
//	std::cout << a::b::c::str << ' ' << iNumbers << ' ' << iSum << '\n';
//
//	std::array arr{ 1,2,3 };
//
//	std::cout << std::size(arr) << '\n';
//
//	return 0;
//}

//#include <iostream>
//
//int main()
//{
//	std::cout << "Enter a number: ";
//	int x{};
//	std::cin >> x;
//	std::cout << "You entered " << x << '\n';
//	return 0;
//}

//#include <iostream>
//
//void doNothing(int&)
//{
//}
//
//int main()
//{
//	int x;
//	doNothing(x);
//	std::cout << x;
//	return 0;
//}