#include <iostream>
#include <limits>

int main() {
    int width(5);
    int length{6};
    

    std::cout << width;
    std::cout << length << std::endl;
    
    std::cin.clear(); // reset any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
    std::cin.get(); // get one more char from the user
}
