#include <string>
#include<iostream>
#include <cmath>
#include<string>
#include "Number.h"

Number::Number(const char* value, int base) : value(value), base(base) {}
Number::Number(int value) : value(std::to_string(value)), base(10) {}
Number::~Number() {}

Number::Number(const Number& other) : value(other.value), base(other.base) {}

Number::Number(Number&& other) noexcept : value(other.value), base(other.base) 
{
    other.value.clear();
    other.base = 0;
}

int ToInteger(std::string s)
{
    int number = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' and s[i] <= '9')
            number = number * 10 + (s[i] - '0');
        else if (s[i] >= 'A' and s[i] <= 'F')
            number = number * 10 + (s[i] - 'A' + 10);
        else if (s[i] >= 'a' and s[i] <= 'f')
            number = number * 10 + (s[i] - 'a' + 10);
    }
    return number;
}

void ToString(int number, std::string& s)
{
    int cnt = 0;
    while (number)
    {
        int digit = number % 10;
        s.push_back((digit + '0'));
        number /= 10;
    }
}
Number& Number::operator=(const Number& other) 
{
    if (this != &other)
    {
        value = other.value;
        base = other.base;
    }
    return *this;
}

Number& Number::operator=(Number&& other) noexcept
{
    if (this != &other) 
    {
        value = other.value;
        base = other.base;
        other.value.clear();
        other.base = 0;
    }
    return *this;
}
Number& Number::operator+=(const Number& other)
{

    Number temp1 = *this;
    std::string sum;
    int max_base;
    if (base > other.base) max_base = base;
    else max_base = other.base;
    temp1.SwitchBase(10);
    Number temp2 = other;
    temp2.SwitchBase(10);

    int sum_value = ToInteger(temp1.value) + ToInteger(temp2.value);
    ToString(sum_value, sum);
    value = sum;
    base = max_base;

    return *this;
}

Number& Number::operator=(int value) 
{
    std::string new_value = "";
    int base = this->base;
    while (value > 0) 
    {
        int r = value % base;
        char digit;
        if (r < 10)
            digit = '0' + r;
        else
            digit = 'A' + r - 10;
        new_value = digit + new_value;
        value /= base;
    }
    this->value = new_value;
    return *this;
}

Number& Number::operator=(const char* value) 
{
    this->value = value;
    return *this;
}

Number& Number::operator--()
{
    for (int i = 0;i < this->GetDigitsCount();i++)
    {
        this->value[i] = this->value[i + 1];
    }
    this->value.pop_back();
    return *this;
}
Number& Number::operator--(int) 
{
    this->value.pop_back();
    return *this;
}
Number operator+(const Number& nr1, const Number& nr2)
{
    int sum_value;
    int sum_base;
    if (nr1.base > nr2.base)
    {
        sum_base = nr1.base;
    }
    else
        sum_base = nr2.base;
    Number temp1 = nr1;
    temp1.SwitchBase(10);
    Number temp2 = nr2;
    temp2.SwitchBase(10);
    sum_value = ToInteger(temp1.value) + ToInteger(temp2.value);
    Number sum(sum_value);
    sum.SwitchBase(sum_base);

    return sum;

}
Number operator-(const Number& nr1, const Number& nr2) 
{
    int diff_value;
    int diff_base;
    if (nr1.base > nr2.base)
    {
        diff_base = nr1.base;
    }
    else
        diff_base = nr2.base;
    Number temp1 = nr1;
    temp1.SwitchBase(10);
    Number temp2 = nr2;
    temp2.SwitchBase(10);
    diff_value = ToInteger(temp1.value) - ToInteger(temp2.value);
    Number diff(diff_value);
    diff.SwitchBase(diff_base);

    return diff;
}
bool Number::operator>(const Number& other) const 
{

    Number temp1 = *this;
    temp1.SwitchBase(10);
    Number temp2 = other;
    temp2.SwitchBase(10);
    return ToInteger(temp1.value) > ToInteger(temp2.value);
}

bool Number::operator<(const Number& other) const 
{

    Number temp1 = *this;
    temp1.SwitchBase(10);
    Number temp2 = other;
    temp2.SwitchBase(10);
    return ToInteger(temp1.value) < ToInteger(temp2.value);
}
bool Number::operator>=(const Number& other) const
{

    Number temp1 = *this;
    temp1.SwitchBase(10);
    Number temp2 = other;

    temp2.SwitchBase(10);
    return ToInteger(temp1.value) >= ToInteger(temp2.value);
}
bool Number::operator<=(const Number& other) const 
{

    Number temp1 = *this;
    temp1.SwitchBase(10);
    Number temp2 = other;
    temp2.SwitchBase(10);
    return ToInteger(temp1.value) <= ToInteger(temp2.value);
}
bool Number::operator==(const Number& other) const 
{

    Number temp1 = *this;
    temp1.SwitchBase(10);
    Number temp2 = other;
    temp2.SwitchBase(10);
    return ToInteger(temp1.value) == ToInteger(temp2.value);
}
void Number::SwitchBase(int newBase) 
{
    if (base == newBase)  return;

    int decimalValue = 0;
    int p = 1;
    for (int i = value.length() - 1; i >= 0; i--) 
    {
        int digitValue;
        if (value[i] >= '0' && value[i] <= '9') 
        {
            digitValue = value[i] - '0';
        }
        else 
        {
            digitValue = value[i] - 'A' + 10;
        }
        decimalValue += digitValue * p;
        p = p * base;
    }

    value = "";
    base = newBase;
    while (decimalValue > 0) 
    {
        int r = decimalValue % newBase;
        char digit;
        if (r < 10)
            digit = '0' + r;
        else
            digit = 'A' + r - 10;
        value = digit + value;
        decimalValue /= newBase;
    }
}
char Number::operator[](int index)
{
    return value[index];
}
void Number::Print()
{
    std::cout << value << std::endl;
}
int Number::GetDigitsCount()
{
    return value.length();
}
int Number::GetBase()
{
    return base;
}