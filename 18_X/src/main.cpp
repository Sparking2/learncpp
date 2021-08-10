#include <vector>
#include <iostream>

#include "triangle.h"
#include "circle.h"

int getLargestRadius(const std::vector<Shape*>& v) {

    Circle* biggest{ new Circle{Point{0,0,0},0} };

    for (Shape* s : v) {
        if (auto * c{ dynamic_cast<Circle*>(s) }) {
            if (c->getRadius() > biggest->getRadius()) {
                biggest = c;
            }
        }
    }

    return biggest->getRadius();
}

int main() {

    std::vector<Shape*> v{
        new Triangle{Point{1,2,3}, Point{4,5,6}, Point{7,8,9}},
        new Circle{Point{4,5,6},3},
        new Circle{Point{1,2,3},7}
    };

    // print each shape in vector v on its own line
    for (Shape* s : v) {
        std::cout << *s << '\n';
    }

    std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

    // delete each element in the vector

    for (const Shape* s : v) {
        delete s;
    }

    return 0;
}