#include <iostream>
#include <vector>
#include <algorithm>


static int multiplier{3};

std::vector<int> generateSquares()
{
    std::cout << "Start where?: ";
    int startNum{};
    std::cin >> startNum;

    std::cout << "How many?: ";
    int numNumbers{};
    std::cin >> numNumbers;

    std::vector<int> squares{};

    for (int i{startNum}; i < startNum + numNumbers; i++)
    {
        squares.push_back(i * i * multiplier);
    }

    std::cout << "I generated " << numNumbers << " numbers.\n";

    return squares;
}

int findNearest(std::vector<int> arr, int num)
{
    return *std::min_element(arr.begin(), arr.end(), [num](int a, int b){return std::abs(a-num)<std::abs(b-num);});
}

void play(std::vector<int> &squares)
{
    std::cout << "Do you know what each number is after multiplying it by " << multiplier << "?\n";
    int guess{};
    int search{};

    while (true)
    {
        break;
    }
}

int main()
{
    std::vector<int> squares{generateSquares()};
    play(squares);

    return 0;
}
