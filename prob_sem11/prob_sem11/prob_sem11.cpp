#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)  // am inlocuit i<=n-1 cu i<n-1 si i=1 cu i=0
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) // am inlocuit j<=n cu j<n
        {
            if (arr[j] < arr[minIndex]) // am inlocuit arr[j] > arr[minIndex] cu arr[j] < arr[minIndex]
            {
                minIndex = j;
               // T temp = arr[minIndex];
                //arr[minIndex] = arr[j];
                //arr[j] = temp;
                //minIndex = j;
            }
        }
        if (minIndex != i) 
        {
            T temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

template <typename T>
void printList(T arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() 
{
    
    int List[] = {6, 0, 2, 1, 4, 6, 3, 1};
    int n = sizeof(List) / sizeof(List[0]);
    selectionSort<int>(List,n);
    printList<int>(List,n);
    return 0;
}
