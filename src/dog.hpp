#include "pet.hpp"

class Dog : Pet {
public:
    Dog(const std::string &name, int age);

    std::string bark() const noexcept;
};
