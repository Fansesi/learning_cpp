#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <utility>
#include <limits>

template <typename T>
void arrayRepr(const std::vector<T>& vec)
{
    std::cout << "Array( ";
    for (const T& elmnt: vec)
    {
        std::cout << elmnt << ", ";
    }
    std::cout << ")\n";
}

template <typename T>
std::pair<size_t, size_t> getMinMax(const std::vector<T>& vec)
{
    if (vec.empty()) {std::cout << "Array is empty.";}
    else {arrayRepr(vec);}

    size_t minIdx{};
    size_t maxIdx{};

    for (size_t i{0}; i<std::size(vec); i++)
    {
        if (vec[i] > vec[maxIdx]) {maxIdx = i; continue;}
        else if (vec[i] < vec[minIdx]) {minIdx = i; continue;}
        // else {continue;}
    }

    return {minIdx, maxIdx};
}

template <typename T>
void printMaxminVec(const std::vector<T>& vec, const std::pair<size_t, size_t>& max_min)
{
    std::cout << "The min element has index " << max_min.first << " and value " << vec[max_min.first] << "\n";
    std::cout << "The max element has index " << max_min.second << " and value " << vec[max_min.second] << "\n";
}

std::vector<int> getVector()
{
    std::cout << "Enter numbers to create the vector (use -1 to stop): ";
    std::vector<int> vec {};
    
    while (true)
    {
        int input {};
        std::cin >> input;
        if (input == -1) {break;}
        if (!std::cin) // if the previous extraction failed
        {
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
            continue;
        }
        vec.push_back(input);
    }

    return vec;
} 


int main()
{
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

    std::vector<int> vec {getVector()};

    printMaxminVec(vec, getMinMax(vec));


    return 0;
}
