#include <iostream>

long double operator"" _Kelvin(const long double x)
{
    return x - 273.15;
}

long double operator"" _Fahrenheit(const long double x)
{
    return (x - 32) * 5 / 9;
}

int main()
{
    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;

    std::cout << "Kelvin to Celsius: " << a << std::endl;
    std::cout << "Fahrenheit to Celsius: " << b << std::endl;

    return 0;
}
