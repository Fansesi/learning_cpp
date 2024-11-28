#include <iostream>
#include <array>
#include <string>

using namespace std::string_literals;
using namespace std::string_literals;

namespace Animal
{
    struct Data 
    {
        std::string_view name {};
        int numLegs {};
        std::string_view sound {};
    };

    enum Type
    {
        chicken, 
        dog, 
        cat, 
        elephant, 
        duck, 
        snake,
        totalAnimalNum
    };

    constexpr std::array types {chicken, dog, cat, elephant, duck, snake};

    std::array<Data, Animal::totalAnimalNum> data {
        Data{ "chicken",    2, "cluck" },
        Data{ "dog",        4, "woof" },
        Data{ "cat",        4, "meow" },
        Data{ "elephant",   4, "pawoo" },
        Data{ "duck",       2, "quack" },
        Data{ "snake",      0, "hissss" },
    };
    static_assert(std::size(types) == totalAnimalNum);
    static_assert(std::size(data) == totalAnimalNum);
}

int main() {
    
    return 0;
}
