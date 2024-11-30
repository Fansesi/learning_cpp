#include <iostream>

int main()
{

    int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
    constexpr int length{static_cast<int>(std::size(array))};

    for (int j{length}; j > 0; j--)
    {
        bool swapped{false};
        
        for (int i{0}; i < j - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                std::swap(array[i], array[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            std::cout << "Iteration ended early on " << length - j + 1 << "\n";
            break;
        }
    }

    for (int elmnt: array)
    {
        std::cout << elmnt << " ";
    }

    return 0;
}
