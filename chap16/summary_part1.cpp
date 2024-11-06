#include <iostream>
#include <vector>
#include <string>
#include <cassert>

namespace Items
{
    enum Type 
    {
        potions,
        torches,
        arrows,
        itemCount
    };

    std::vector<int> inventory {1, 5, 10};

    std::string getItemName(size_t x)
    {
        switch (x)
        {
        case 0:
            return "health potions";
        case 1:
            return "torches";
        case 2:
            return "arrows";
        default:
            return "???";
        }
    }
}


template <typename T>
T sumVector(const std::vector<T>& vec)
{
    T sum {0};

    for (const auto& elmnt: vec)
    {
        sum+=elmnt;
    }
    return sum;

}


void initQuestions()
{
    using namespace std::literals::string_view_literals; // for sv suffix
    std::vector<int> evenNums {0, 2, 4, 6, 8, 10};
    const std::vector<float> someNums {1.2, 3.4, 5.6, 7.8};
    const std::vector someChars {"Alex"sv, "Brad"sv, "Charles"sv, "Dave"sv};
    std::vector single {12};
    std::vector<int> allZeroInit (12);
}


template <typename T>
void printInventory(const std::vector<T>& vec)
{
    assert(std::size(vec) == Items::itemCount);

    for (size_t i = 0; i < Items::itemCount; i++)
    {
        std::cout << "You have " << Items::inventory[i] << " " << Items::getItemName(i) << "\n";
    }
}


int main() { 
    printInventory(Items::inventory);
    return 0;
}
