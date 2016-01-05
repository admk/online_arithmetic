#include <iostream>
#include "int.hpp"


int main(int argc, const char * argv[]) {
    OA::Int<8> a = 8;
    OA::Int<8> b = 9;
    a = a + b;
    std::cout << a.upper << ", " << a.lower << std::endl;
    std::cout << (int)a << std::endl;
    return 0;
}
