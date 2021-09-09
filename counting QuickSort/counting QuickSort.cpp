#include <iostream>
#include <fstream>
#include <chrono>
#include<functional>
#include <algorithm>
#include <time.h>
using namespace std;
void QuickSort(float arr[], int low, int high);
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int main()
{
    ifstream fi("10.inp");
    if (fi.fail() == true)
    {
        cout << "import false";
        return 0;
    }
    float* p;
    p = new float[1000000];
    for (int i = 0; i < 1000000; i++)
        fi >> p[i];
    clock_t t = clock();
    QuickSort(p, 0, 999999) ;
    t = clock() - t;
    cout << t;
    fi.close();
    delete[]p;
    return 0;
}
void QuickSort(float arr[], int left, int right)
{
    if (left >= right)
        return;
    int middle = (left + right) / 2;
    float pivot = arr[middle];
    int i = left, j = right;
    while (i <= j)
    {

        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        QuickSort(arr, left, j);
    if (right > i)
        QuickSort(arr, i, right);
}