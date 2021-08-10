#pragma once

#include "animal.h"

class Dog : public Animal {
public:
    Dog(std::string_view name)
        : Animal{ name , "Woof" }
    {}

    std::string_view speak() const { return "Woof"; }
};