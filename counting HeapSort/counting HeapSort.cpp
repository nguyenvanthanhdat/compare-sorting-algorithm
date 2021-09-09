#include <iostream>
#include <fstream>
#include <chrono>
#include<functional>
#include <algorithm>
#include <time.h>
using namespace std;
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
int cmpfunc(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int main()
{
    ifstream fi("5.inp");
    if (fi.fail() == true)
    {
        cout << "import false";
        return 0;
    }
    int* p;
    p = new int[1000000];
    for (int i = 0; i < 1000000; i++)
        fi >> *(p + i);
    clock_t t = clock();
    heapSort(p, 1000000);
    t = clock() - t;
    cout << t;
    fi.close();
    delete[]p;
    return 0;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}