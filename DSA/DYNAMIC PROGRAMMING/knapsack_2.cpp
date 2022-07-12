#include <bits/stdc++.h>
#include <climits>
using namespace std;
const int N = 100005;
long long int dp[105][N];
int n;
long long int w;
vector<pair<int, int>> arr;
long long int knapsack2(int ind, int value)
{
    if (value == 0)
        return 0;
    if (ind < 0)
        return 1e15;
    if (dp[ind][value] != -1)
        return dp[ind][value];
    long long int ans = knapsack2(ind - 1, value); // not choosing.
    if (value - arr[ind].second >= 0)
        ans = min(ans, knapsack2(ind - 1, value - arr[ind].second) + arr[ind].first); // choosing
    return  dp[ind][value] =ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    memset(dp, -1, sizeof(dp));
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        int key1;
        int key2;
        cin >> key1 >> key2;
        arr.push_back({key1, key2});
    }
    for (int i = 0; i < 1e5; i++)
    {
    }
    for (int i = 1e5; i >= 0; i--)
    {
        if (knapsack2(n - 1, i) <= w)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}