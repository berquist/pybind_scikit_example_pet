#include <string>
#include "holder.hpp"

class Pet {
public:
    Pet(const std::string &name, int age);

    void setName(const std::string &name_);
    const std::string &getName() const noexcept;

    void set(int age_);
    void set(const std::string &name_);

    template<typename T>
    bool mymethod(const holder<T> &h1) const noexcept {
        return false;
    }

    bool mymethod(const std::string &a1) const noexcept;

private:
    std::string name;
    int age;
};
