#include <iostream>

int factorial(int n)
{
    if (n == 2)
    {
        return n;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int sumDigits(int num)
{
    static int digitSum{0};

    if (num < 10)
    {
        return digitSum + num;
    }

    int rightDigit{num % 10};
    digitSum += rightDigit;

    return sumDigits((num - rightDigit) / 10);
}

int sumDigits_v2(int num)
{
    if (num < 10)
    {
        return num;
    }
    return sumDigits_v2(num / 10) + num % 10;
}

void binary(int num)
{
    if (num == 0)
    {
        return;
    }
    binary(num / 2);
    std::cout << num % 2;
}

int main()
{
    // std::cout << factorial(6) << "\n";
    // std::cout << sumDigits(1000) << "\n";
    binary(14);
    return 0;
}
