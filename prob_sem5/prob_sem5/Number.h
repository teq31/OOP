#pragma once
#include<string>
class Number
{
private:
	std::string value;
	int base;
public:
	Number(const char* value, int base);
	Number(int value);
	~Number();

	Number(const Number& other);
	Number(Number&& other) noexcept;
	Number& operator=(const Number& other);
	Number& operator=(Number&& other) noexcept;
	Number& operator+=(const Number& other);
	Number& operator=(int value);
	Number& operator=(const char* value);
	Number& operator--();
	Number& operator--(int);


	friend Number operator+(const Number& nr1, const Number& nr2);
	friend Number operator-(const Number& nr1, const Number& nr2);
	bool operator>(const Number& other) const;
	bool operator<(const Number& other) const;
	bool operator>=(const Number& other) const;
	bool operator<=(const Number& other) const;
	bool operator==(const Number& other) const;
	char operator[](int index);


	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount();
	int GetBase();
};