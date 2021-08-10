#pragma once

#include "animal.h"

class Cat : public Animal {
public:
    Cat(std::string_view name)
        : Animal{ name , "Meow" }
    {}

    std::string_view speak() const { return "Meow"; }
};