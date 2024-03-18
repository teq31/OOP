#include "Sort.h"
#include <iostream>
#include <vector>

int main()
{
    // Elemente random intre 1 si 100
    Sort s1(10, 1, 100);
    std::cout << "Random Elements: ";
    s1.Print();

    // InsertSort
    s1.InsertSort(true);
    std::cout << "Sorted Elements (Ascending): ";
    s1.Print();

    s1.InsertSort(false);
    std::cout << "Sorted Elements (Descending): ";
    s1.Print();

    // Lista initializata
    Sort s2{ 5, 4, 3, 2, 1 };
    std::cout << "Initializer List Elements: ";
    s2.Print();

    // QuickSort
    s2.QuickSort(true);
    std::cout << "Sorted Elements (Ascending): ";
    s2.Print();

    // Vector existent
    std::vector<int> vec{ 10, 30, 40, 20, 50 };
    Sort s3(vec, 3);
    std::cout << "Vector Elements: ";
    s3.Print();

    // BubbleSort
    s3.BubbleSort(true);
    std::cout << "Sorted Elements (Ascending): ";
    s3.Print();

    // va_args
    Sort s4(5, 10, 20, 30, 40, 50);
    std::cout << "Variadic Parameters Elements: ";
    s4.Print();

    // string
    Sort s5("10,40,100,5,70");
    std::cout << "String Elements: ";
    s5.Print();

    // Numar elemente
    std::cout << "Elements Count in s5: " << s5.GetElementsCount() << std::endl;

    // Element pozitia X
    int index = 2;
    std::cout << "Element at index " << index << " in s5: " << s5.GetElementFromIndex(index) << std::endl;

    return 0;
}
