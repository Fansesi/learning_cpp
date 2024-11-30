#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>

std::size_t getNumNames()
{
    std::cout << "How many names will you enter: ";
    std::size_t numNames{};
    std::cin >> numNames;
    return numNames;
}

template <typename T>
void printArray(T* arr, std::size_t length)
{
    for (size_t i{0}; i < length; i++)
    {
        std::cout << "Name #" << i + 1 << ": " << arr[i] << '\n';
    }
    
}

int main() {
    std::size_t numNames{getNumNames()};

    auto* names{ new std::string[numNames]{} };

    for (size_t i{0}; i < numNames; i++)
    {
        std::cout << "Enter name #" << i+1 << ": ";
        std::getline(std::cin >> std::ws, names[i]);
    }


    std::sort(names, names + numNames);
    printArray(names, numNames);
    delete[] names;

    return 0;
}
