import scikit_build_example as m


def test_version():
    assert m.__version__ == "0.0.1"


def test_add():
    assert m.add(1, 2) == 3


def test_sub():
    assert m.subtract(1, 2) == -1


def test_pet():
    name = "Bob"
    age = 12
    pet = m.Pet(name, age)
    print(dir(pet))
    help(pet.set_name)
    help(pet.get_name)
    help(pet.set)
    # print(pet.name)
    # print(pet.age)
    help(pet.mymethod)


def test_dog():
    # dog = m.Dog("Steve", 9)
    name = "Steve"
    age = 9
    dog = m.Dog(name, age)
    print(dog.bark())
