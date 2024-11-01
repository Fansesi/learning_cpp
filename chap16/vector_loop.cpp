#include <iostream>
#include <vector>

template <typename T>
void printVec(const std::vector<T>& vec)
{
    for (size_t i{0}; i < std::size(vec); i++)
    {
        std::cout << i << " ";
    }
    
}

template <typename T, typename U>
void isInside(const std::vector<T>& vec, const U& num)
{
    for (size_t i {0}; i < std::size(vec); i++)
    {
        if (vec.at(i) == num) {std::cout << "It's on the index: " << i; return;}
    }
    std::cout << "Couldn't find it.";
    return;
    
}

template <typename T>
T findMax(const std::vector<T>& vec)
{
    // check empty array
    if (!std::size(vec)) {return 0;}

    std::size_t max_i{};
    for (std::size_t i = 0; i < std::size(vec); i++)
    {
        if (vec[i] >= vec[max_i]) {max_i = i;}
    }
    
    return vec[max_i];
}

int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    // std::cout << "Write a num: ";
    // int num;
    // std::cin >> num;
    // isInside(arr, num);

    std::vector data1 { 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3 { };
    std::cout << findMax(data3) << '\n';

    return 0;
}
