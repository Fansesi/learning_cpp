#include <iostream>
#include <array>
#include <string>
#include <algorithm>


struct Student
{
    std::string name{};
    int point{};
};

template<std::size_t N>
void printBestStudent(std::array<Student, N>& students)
{
    auto best = std::max_element(std::begin(students), std::end(students), [](Student a, Student b){return (a.point<b.point);});
    std::cout << best->name << " is the best student.\n";
}

int main()
{
    std::array<Student, 8> arr{
        {{"Albert", 3},
         {"Ben", 5},
         {"Christine", 2},
         {"Dan", 2}, // Dan has the most points (8).
         {"Enchilada", 4},
         {"Francis", 1},
         {"Greg", 3},
         {"Hagrid", 5}}};
    
    printBestStudent(arr);

    return 0;
}
