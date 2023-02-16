#include "pet.hpp"
#include <iostream>

Pet::Pet(const std::string &name, int age)
    : name(name)
    , age(age)
{ }

void Pet::setName(const std::string &name_) {
    name = name_;
}

const std::string &Pet::getName() const noexcept {
    return name;
}

void Pet::set(int age_) {
    age = age_;
}

void Pet::set(const std::string &name_) {
    name = name_;
}

bool Pet::mymethod(const std::string &a1) const noexcept {
    std::cout << "a1=" << a1 << std::endl;
    return true;
}
