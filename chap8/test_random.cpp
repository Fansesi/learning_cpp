#include <iostream>
#include "Random.h"

int main()
{
    for (int i{0}; i < 100; i++)
    {
        std::cout << Random::get(1, 100) << "\n";
    }
    
}
