#include <iostream>
#include <vector>


template <typename T>
const T printElement(const std::vector<T>& arr, const int i)
{   
    if (i >= static_cast<int>(std::size(arr)))
    {
        std::cout << "Index out of bounds!";
        return 0;
    } else
    {
        return arr[static_cast<std::size_t>(i)];
    }
}

int main()
{
    std::vector vec{"h", "e", "l", "l", "o"};
    std::cout << "Vec size: " << std::size(vec) << "\n";
    std::cout << "vec[1]: " << vec[1] << "\n";

    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}
