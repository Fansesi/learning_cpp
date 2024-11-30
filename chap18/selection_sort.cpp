#include <iostream>
#include <array>

void selection_sort(int arr[5])
{
    constexpr int length{5};

    for (int startIndex{0}; startIndex < length; startIndex++)
    {
        int biggestIndex{startIndex};

        for (int currentIndex{biggestIndex}; currentIndex < length; currentIndex++)
        {
            if (arr[currentIndex] > arr[biggestIndex])
            {
                biggestIndex = currentIndex;
            }
        }
        std::swap(arr[startIndex], arr[biggestIndex]);
    }
    
}



int main()
{
    int array[5]{30, 50, 20, 10, 40};
    constexpr int length{static_cast<int>(std::size(array))};

    // Step through each element of the array
    // (except the last one, which will already be sorted by the time we get there)
    for (int startIndex{0}; startIndex < length - 1; ++startIndex)
    {
        // smallestIndex is the index of the smallest element we’ve encountered this iteration
        // Start by assuming the smallest element is the first element of this iteration
        int smallestIndex{startIndex};

        // Then look for a smaller element in the rest of the array
        for (int currentIndex{startIndex + 1}; currentIndex < length; ++currentIndex)
        {
            // If we've found an element that is smaller than our previously found smallest
            if (array[currentIndex] < array[smallestIndex])
                // then keep track of it
                smallestIndex = currentIndex;
        }

        // smallestIndex is now the index of the smallest element in the remaining array
        // swap our start element with our smallest element (this sorts it into the correct place)
        std::swap(array[startIndex], array[smallestIndex]);
    }

    // Now that the whole array is sorted, print our sorted array as proof it works
    for (int index{0}; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';


    selection_sort(array);

    for (int index{0}; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';

    return 0;
}
