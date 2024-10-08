#include <iostream>
#include <string>

int getAge(std::string_view name)
{
    std::cout << "Enter the age of " << name << ": ";
    int age;
    std::cin >> age;

    return age;
}

const std::string getName(int personNumber)
{
    std::string name{};
    std::cout << "Enter the name of the person #" << personNumber << ": ";
    std::getline(std::cin >> std::ws, name);

    return name;
}

int main()
{
    const std::string name1{getName(1)};
    const std::string name2{getName(2)};
    const int age1{getAge(name1)};
    const int age2{getAge(name2)};

    if (age1 > age2)
        std::cout << name1 << "(age " << age1 << ") " << "is older than " << name2 << " (age " << age2 << ")";
    else
        std::cout << name2 << "(age " << age2 << ") " << "is older than " << name1 << " (age " << age1 << ")";
    
    std::cout << "\n\n";
    
    return 0;
}
