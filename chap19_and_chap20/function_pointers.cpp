#include <iostream>
#include <limits>
#include <vector>
#include <functional>

using ArthmeticFunction = std::function<int(int, int)>; 

std::vector<int> getNumbers(int nNumbers = 2)
{
    std::vector<int> numbersArr{};
    for (std::size_t i{0}; i < static_cast<std::size_t>(nNumbers); i++)
    {
        std::cout << "Enter number #" << i << ": ";
        std::cin >> numbersArr.data()[i];
    }

    return numbersArr;
}

char getOperation()
{
    std::cout << "Choose one from +, -, / or *: ";
    char op{};
    std::cin >> op;

    if (!std::cin)
    {
        std::cin.clear();                                                   // put us back in 'normal' operation mode
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
    }
    return op;
}

namespace OP
{
    int add(int a, int b) { return a + b; }
    int subtract(int a, int b) { return a - b; }
    int divide(int a, int b) { return a / b; }
    int multiply(int a, int b) { return a * b; }
}

ArthmeticFunction getArithmeticFunction(char op)
{
    switch (op)
    {
    case '+':
        return OP::add;
    case '-':
        return OP::subtract;
    case '/':
        return OP::divide;
    case '*':
        return OP::multiply;
    
    default:
        break;
    }
    return nullptr;
}

int main()
{
    char op{getOperation()};
    auto numbers{getNumbers(2)};
    auto func{getArithmeticFunction(op)};
    
    func(numbers[0], numbers[1]);
    
    return 0;
}
