//Write a class named RGBA that contains 4 member variables of type
//std::uint_fast8_t named m_red, m_green, m_blue, and m_alpha(#include cstdint to access type std::uint_fast8_t).
//Assign default values of 0 to m_red, m_green, and m_blue, and 255 to m_alpha.
//Create a constructor that uses a member initializer list that allows the user to initialize values for m_red, m_blue, m_green, and m_alpha.
//Include a print() function that outputs the value of the member variables.
//If you need a reminder about how to use the fixed width integers, please review lesson 4.6 --Fixed - width integers and size_t.
//
//Hint : If your print() function isn’t working correctly, make sure you’re casting uint_fast8_t to an int.

#include <iostream>
#include <cstdint>


class RGBA {
public:
	using component_type = std::uint_fast8_t;

private:
	component_type m_red;
	component_type m_green;
	component_type m_blue;
	component_type m_alpha;

public:
	RGBA(component_type red = 0, component_type green = 0, component_type blue = 0, component_type alpha = 255) :
		m_red{ red }, m_green{ green }, m_blue{ blue }, m_alpha{ alpha }
	{
	}

	void print() {
		std::cout << 
			" r=" << static_cast<int>(m_red) <<
			" g=" << static_cast<int>(m_green) <<
			" b=" << static_cast<int>(m_blue) <<
			" a=" << static_cast<int>(m_alpha) <<
			'\n';
	}
};

int Ch_11_6_Question1()
{
	RGBA teal{ 0, 127, 127 };
	teal.print();

	return 0;
}

//Expected result: r=0 g=127 b=127 a=255