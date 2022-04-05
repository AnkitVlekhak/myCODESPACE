#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int rat(int a[], int l, int b)
{
    while (b > l)
    {
        swap(a[l], a[b]);
        l++;
        b--;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int l, b;
    rat(a, 0, 4);
    rat(a, 5, 8);
    rat(a, 0, 8);
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}
