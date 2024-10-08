#include <iostream>



int main()
{
    std::cout << "Enter an integer: ";
    int smaller{};
    std::cin >> smaller;

    std::cout << "Enter a larger integer: ";
    int larger{};
    std::cin >> larger;

    if (smaller > larger)
    {
        std::cout << "Swapping the values.\n";
        int tmp{}; // I could have initiated the tmp here.
        tmp = smaller;
        smaller = larger;
        larger = tmp;
    }
    else
    {
        std::cout << "Thanks for actually giving larger integer.\n";
    }
    
    std::cout << "Smaller value is: " << smaller << "\n";
    std::cout << "Larger value is: " << larger << "\n\n";    
}
