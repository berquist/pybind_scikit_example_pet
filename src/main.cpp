// Don't forget to add implementations under `pybind11_add_module` in
// CMakeLists.txt; compiling the module will work and you'll get cryptic
// "undefined symbol" errors only at library import time, like when trying to
// run Python-side tests
#include "dog.hpp"

#include <pybind11/pybind11.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

int add(int i, int j) {
    return i + j;
}

namespace py = pybind11;

template <typename... Args>
using overload_cast_ = pybind11::detail::overload_cast_impl<Args...>;

PYBIND11_MODULE(_core, m) {
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------

        .. currentmodule:: scikit_build_example

        .. autosummary::
           :toctree: _generate

           add
           subtract
    )pbdoc";

    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers

        Some other explanation about the subtract function.
    )pbdoc");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif

    // dynamic_attr here causes segfault for Dog?
    py::class_<Pet> pet(m, "Pet");
    pet.def(py::init<const std::string &, int>())
        .def("set_name", &Pet::setName, "Set the pet's name")
        .def("get_name", &Pet::getName, "Get the pet's name")
        // .def("set", static_cast<void (Pet::*)(int)>(&Pet::set), "Set the pet's age")
        // .def("set", static_cast<void (Pet::*)(const std::string &)>(&Pet::set), "Set the pet's name")
        .def("set", overload_cast_<int>()(&Pet::set), "Set the pet's age")
        .def("set", overload_cast_<const std::string &>()(&Pet::set), "Set the pet's name")
        ;

    py::class_<Dog>(m, "Dog", pet)
        .def(py::init<const std::string &, int>())
        .def("bark", &Dog::bark)
        ;
}
