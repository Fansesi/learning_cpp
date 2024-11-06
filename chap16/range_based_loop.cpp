#include <iostream>
#include <vector>
#include <string>


template <typename T>
bool isValueInArray(const std::vector<T>& arr, const T& val)
{
    for (const T& elmnt: arr)
    {
        if (elmnt == val) {return true;}
    }
    return false;
}

int main() {
    const std::vector<std::string> names {"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

    const std::string someName{"Alex"};
    std::cout << isValueInArray(names, someName);
    exit(0);

    std::string username{};
    std::cin >> username;

    // similar to python's 'in' keyword
    for (const std::string_view name: names)
    {
        if (username == name)
            {std::cout << "Match!"; exit(0);}
    }
    std::cout << "Couldn't find it!";

   

    return 0;
}
