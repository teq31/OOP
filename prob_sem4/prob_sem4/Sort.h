#pragma once
#include <vector>
#include <initializer_list>
#include <string>
class Sort
{
    std::vector<int> elem;
public:
    Sort(int count, int min, int max);
    Sort(std::initializer_list<int> list);
    Sort(int v[100], int count);
    Sort(int count, ...);
    Sort(const std::string& str);


    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void QSRecursiv(int st, int dr, bool ascendent = false);
    int Part(int st, int dr, bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};