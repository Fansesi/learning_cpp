#include <iostream>
#include <string>

enum Animal
{
    cow,
    chicken,
    goat,
    dog,
    duck,
    cat,
};

constexpr std::string_view getAnimalName(Animal animalName)
{
    switch (animalName)
    {
    case cow: {return "cow";}
    case chicken: {return "chicken";}
    case goat: {return "goat";}
    case dog: {return "dog";}
    case duck: {return "duck";}
    case cat: {return "cat";}
    
    default: {return "???";}
    }
    return;
}

constexpr int printNumberOfLegs(Animal animalName)
{
    switch (animalName)
    {
    case cow: {return 4;}
    case chicken: {return 2;}
    case goat: {return 4;}
    case dog: {return 4;}
    case duck: {return 2;}
    case cat: {return 4;}
    
    default: {return 0;}
    }
    return;
}

int main()
{
    Animal mydog{dog};

    return 0;
}
