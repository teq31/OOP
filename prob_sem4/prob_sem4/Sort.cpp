#include "Sort.h"
#include <iostream>
#include <algorithm>
#include <cstdarg>

Sort::Sort(int count, int min, int max)
{
	for (int i = 0; i < count; i++)
		elem.push_back(rand() % (max - min + 1) + min);
}

Sort::Sort(std::initializer_list<int> list)
{
	for (int num : list) elem.push_back(num);
}

Sort::Sort(int v[100], int count)
{
	for (int i = 0; i < count; i++) elem.push_back(v[i]);
}

Sort::Sort(int count, ...) 
{
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; ++i)
	{
		int value = va_arg(args, int);
		elem.push_back(value);
	}
	va_end(args);
}

Sort::Sort(const std::string& str)
{
	int number = 0;
	for (int i = 0; i < str.size(); i++) 
	{
		char c = str[i];
		if (c == ',')
		{
			elem.push_back(number);
			number = 0;
		}
		else 
		{
			int cif = c - '0';
			number =number * 10 + cif;
		}
	}
	if (number!=0)
		elem.push_back(number);
}


void Sort::InsertSort(bool ascendent)
{
	int count = elem.size();
	for (int i = 1; i < count; i++)
	{
		int key = elem[i];
		int j = i - 1;

		while (j >= 0 && ((ascendent && elem[j] > key) || (!ascendent && elem[j] < key)))
		{
			elem[j + 1] = elem[j];
			j = j - 1;
		}
		elem[j + 1] = key;
	}
}


int Sort::Part(int st, int dr, bool ascendent)
{
	int pivot = elem[dr];
	int i = (st - 1);
	for (int j = st; j <= dr - 1; j++)
	{
		if ((ascendent && elem[j] < pivot) || (!ascendent && elem[j] > pivot))
		{
			i++;
			std::swap(elem[i], elem[j]);
		}
	}
	std::swap(elem[i + 1], elem[dr]);
	return (i + 1);
}

void Sort::QSRecursiv(int st, int dr, bool ascendent)
{
	if (st < dr)
	{
		int PartIndex = Part(st, dr, ascendent);
		QSRecursiv(st, PartIndex - 1, ascendent);
		QSRecursiv(PartIndex + 1, dr, ascendent);
	}
}

void Sort::QuickSort(bool ascendent)
{
	QSRecursiv(0, elem.size() - 1, ascendent);
}
void Sort::BubbleSort(bool ascendent)
{
	bool ok = 0;
	int count = elem.size();
	while (!ok)
	{
		ok = 1;
		for(int i = 0; i < count - 1; i++)
			if ((ascendent && elem[i] > elem[i + 1]) || (!ascendent && elem[i] < elem[i+1]))
			{
				int aux = elem[i];
				elem[i] = elem[i + 1];
				elem[i + 1] = aux;
				ok = 0;
			}
	}
}
void Sort::Print()
{
	for (int i = 0; i < elem.size(); i++)
		std::cout << elem[i] << ' ';
	std::cout << std::endl;
}

int Sort::GetElementsCount()
{
	return elem.size();
}
int Sort::GetElementFromIndex(int index)
{
	return elem[index];
}