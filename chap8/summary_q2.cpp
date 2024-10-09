#include <iostream>
#include <math.h>

bool isPrime(int num)
{
    // check edge cases
    if (num!=2 && (num<2 || num % 2 == 0)) {return false;}
    
    for (int div{3}; div<=sqrt(num);)
    {
        if (num % div == 0) {return false;}
        div += 2;
    }
    return true;
}

void testPrime(int n)
{
    for (int i{1}; i<=n; i++)
    {
        std::cout << i << ": " << isPrime(i) << "\n"; 
    }
}

int main() 
{   
    std::cout << std::boolalpha;
    testPrime(1000);

    return 0;
}
