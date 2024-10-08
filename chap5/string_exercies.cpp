#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter you name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    int letter_length{static_cast<int>(name.length())};
    std::cout << "Your age + length of name is: " << letter_length + age << "\n\n";

    return 0;
}
