#include <iostream>
#include <string>

void printEven(int n)
{
    for (int i{0}; i<=n; i++)
    {
        if (i % 2 == 0) 
        {
            std::cout << i << "\n";
        }
    }
}

int sumTo(int n) 
{
    static int sumValue {0};

    for (int i{1}; i<=n; i++) 
    {
        sumValue+=i;
    }

    return sumValue;
}

bool isDivisible(int num, int div)
{
    if (num % div == 0)
    {
        return true;
    }
    return false;
}

void fizzbuzzpop(int n)
{
    for (int i{1}; i<=n; i++)
    {   
        std::cout << "\n";
        if (isDivisible(i, 3) || isDivisible(i, 5) || isDivisible(i, 7)) {
            if (isDivisible(i, 3)) {std::cout << "fizz";}
            if (isDivisible(i, 5)) {std::cout << "buzz";}
            if (isDivisible(i, 7)) {std::cout << "pop";}
        }
        else {std::cout << i;}
    }
}

void printASCII() 
{
    for (char a{0}; a<127; a++)
    {
        std::cout << a << "\n";

    }
}

void printPyramid1(int n)
{
    for (int i{n}; i>0; i--)
    {
        for (int j{i}; j>0; j--)
        {
            std::cout << j << " ";
        }
        std::cout << "\n";

    }
}

int main() 
{
    // printEven(20);
    // std::cout << "sum is" << sumTo(5) << "\n\n";
    // fizzbuzzpop(150);
    printPyramid1(9);


    return 0;
}
