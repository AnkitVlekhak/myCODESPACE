#include <bits/stdc++.h>
#include <climits>
using namespace std;
const int N = 1e5 + 10;
vector<int> dp(N, -1);
int n;

int lis(vector<int> arr, int i = n - 1)
{
    int c =1;
    if(dp[i]!=-1){
        return dp[i];
    }
    for (int j = i - 1; j >= 0; j--)
    {
        if (arr[i] > arr[j])
        {
            c = max(c, lis(arr, j) + 1);
        }
    }
    return dp[i]=c;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        arr.push_back(key);
    }
    cout << lis(arr) << endl;
    return 0;
}