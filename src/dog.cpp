#include "dog.hpp"

Dog::Dog(const std::string &name, int age) : Pet(name, age) { }

std::string Dog::bark() const noexcept { return "woof!"; }
