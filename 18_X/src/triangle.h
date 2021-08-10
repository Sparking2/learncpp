#pragma once

#include "shape.h"
#include "point.h"

class Triangle : public Shape {
protected:
    Point m_point1;
    Point m_point2;
    Point m_point3;
public:
    Triangle(Point p1, Point p2, Point p3)
        : m_point1{ p1 }, m_point2{ p2 }, m_point3{ p3 }
    {}

    virtual std::ostream& print(std::ostream& out) const override {
        out << "Triangle(" << m_point1 << ", " << m_point2 << ", " << m_point3 << ")";
        return out;
    }
};