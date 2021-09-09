#include <iostream>
#include <fstream>
#include <chrono>
#include<functional>
#include <algorithm>
#include <time.h>
using namespace std;
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
    sort(p, p+999999);
    t = clock() - t;
    cout << t;
    fi.close();
    delete[]p;
    return 0;
}