#pragma once

#include <string>
#include <string_view>

class Animal {
protected:
    std::string m_name;
    std::string m_speak;

    Animal(std::string_view name, std::string_view speak);
    Animal(const Animal&) = delete;
    Animal& operator=(const Animal&) = delete;
    ~Animal();

public:
    const std::string& getName() const { return m_name; }
    std::string_view speak() const { return m_speak; }
};

Animal::Animal(std::string_view name, std::string_view speak)
    : m_name{ name }, m_speak{ speak }
{}

Animal::~Animal()
{}
