#pragma once

#include <iostream>

class Point {
private:
    int m_x{};
    int m_y{};
    int m_z{};
public:
    Point(int x, int y, int z)
        : m_x{ x }, m_y{ y }, m_z{ z }
    {}

    friend std::ostream& operator<< (std::ostream& out, const Point& p) {
        out << "Point(" << p.m_x << "," << p.m_y << "," << p.m_z << ")";
        return out;
    }
};