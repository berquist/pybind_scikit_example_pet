#include <string>

class Pet {
public:
    Pet(const std::string &name, int age);

    void setName(const std::string &name_);
    const std::string &getName() const noexcept;

    void set(int age_);
    void set(const std::string &name_);

private:
    std::string name;
    int age;
};
