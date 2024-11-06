#include <iostream>
#include <vector>
#include <cassert>

namespace Animals 
{
    enum AnimalTypes
    {
        chicken, 
        dog, 
        cat, 
        elephant,
        duck,
        snake,
        animalNum,
    };
    const std::vector<int> legNums {2, 4, 4, 4, 2, 0};
}

int main() {
    assert(Animals::legNums.size() == Animals::animalNum);
    
    return 0;
}
