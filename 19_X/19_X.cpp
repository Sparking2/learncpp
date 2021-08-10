#include <iostream>

template <class T>
class Pair1
{
private:
    T m_first;
    T m_second;
public:
    Pair1(const T& first, const T& second)
        : m_first(first), m_second(second)
    {}

    const T first() { return m_first; }
    const T second() { return m_second; }
};

template <class T, class P>
class Pair
{
private:
    T m_first;
    P m_second;
public:
    Pair(const T& first, const P& second)
        : m_first(first), m_second(second)
    {}
    const T& first() const { return m_first; }
    const P& second() const { return m_second; }
};

template <class P>
class StringValuePair : public Pair<std::string, P>
{
public:
    StringValuePair(const std::string& key, const P& value)
        : Pair<std::string, P>(key, value)
    {}
};

int main()
{
    StringValuePair<int> svp("Hello", 5);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}