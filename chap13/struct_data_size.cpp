#include <iostream>

struct ExStruct
{
    int a_float{};
    int an_int{}; 
    short a_bool{};
};


int main()
{
    // bool:           1 bytes
    // char:           1 bytes
    // short:          2 bytes
    // int:            4 bytes
    // long:           8 bytes
    // long long:      8 bytes
    // float:          4 bytes
    // double:         8 bytes
    // long double:    16 bytes
    constexpr ExStruct mystruct{};
    std::cout << "Size of this struct: " << sizeof(mystruct);
    return 0;
}
