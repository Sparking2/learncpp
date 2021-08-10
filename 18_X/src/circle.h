#pragma once

#include "shape.h"
#include "point.h"

class Circle : public Shape {
protected:
    Point m_center;
    int m_radius;

public:
    Circle(Point p, int r)
        : m_center{ p }, m_radius{ r }
    {}

    virtual std::ostream& print(std::ostream& out) const override {
        out << "Circle(" << m_center << ", radius " << m_radius << ")";
        return out;
    }

    int getRadius() {
        return m_radius;
    }
};