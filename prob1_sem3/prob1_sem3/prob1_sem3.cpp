#include "Math.h"
#include <iostream>

int main()
{
    std::cout << "Add(3, 5) = " << Math::Add(3, 5) << std::endl;
    std::cout << "Add(3.5, 2.7) = " << Math::Add(3.5, 2.7) << std::endl;
    std::cout << "Add(3, 5, 7) = " << Math::Add(3, 5, 7) << std::endl;
    std::cout << "Add(3.5, 2.7, 1.2) = " << Math::Add(3.5, 2.7, 1.2) << std::endl;
    std::cout << "Mul(3, 5) = " << Math::Mul(3, 5) << std::endl;
    std::cout << "Mul(3.5, 2.7) = " << Math::Mul(3.5, 2.7) << std::endl;
    std::cout << "Mul(3, 5, 7) = " << Math::Mul(3, 5, 7) << std::endl;
    std::cout << "Mul(3.5, 2.7, 1.2) = " << Math::Mul(3.5, 2.7, 1.2) << std::endl;

    std::cout << "Add(5, 10, 15, 20, 25) = " << Math::Add(5, 10, 15, 20, 25) << std::endl;

    const char* s1 = "Hello, ";
    const char* s2 = "world!";
    char* concat = Math::Add(s1, s2);
    if (concat != nullptr)
    {
        std::cout << "Siruri concatenate: " << concat << std::endl;
        delete[] concat;
    }
    else
    {
        std::cout << "Sirurile nu pot fi concatenate" << std::endl;
    }
    return 0;
}