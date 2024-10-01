#include <iostream>

int main() {
    double x;
    double y;
    std::string operation;
    std::cout << "Enter a number (x): ";
    std::cin >> x;
    std::cout << "Enter a number (y): ";
    std::cin >> y;
    std::cout << "Enter +, -, *, or /: ";
    std::cin >> operation;
    
    std::cout << "The result is: ";
    if (operation == "+") {
        std::cout << x+y;
    } else if (operation == "-") {
        std::cout << x-y;  
    } else if (operation == "*") {
        std::cout << x*y;
    } else if (operation == "/") {
        std::cout << x/y;
    } else {
        std::cout << "Incorrect input. Please only use +, -, *, or /.";
    }
    std::cout << "\n\n";
    
    return 0;
}
