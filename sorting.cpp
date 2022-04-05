#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int index;
    for (int i = 0; i < n; i++)
    {
        int m = INT_MAX;
        for (int j = i; j < n; j++)
        {
            int z = m;
            m = min(m, arr[j]);
            if (z != m)
            {
                index = j;
            }
        }
        if (arr[i] != m)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}