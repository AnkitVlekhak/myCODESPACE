#include <bits/stdc++.h>
#include <climits>
using namespace std;
long long int dp[105][100005];
int n;
long long int w;
vector<pair<int,long long int>> arr;
long long int knapsack(int ind, int remaining_weight)
{
    if (remaining_weight == 0)
        return 0;
    if (ind < 0)
        return 0;
    if (dp[ind][remaining_weight] != -1)
        return dp[ind][remaining_weight];
    long long int ans = knapsack(ind - 1, remaining_weight);
    if (remaining_weight - arr[ind].first >= 0)
        ans = max(ans, knapsack(ind - 1, remaining_weight - arr[ind].first) + arr[ind].second);

    return dp[ind][remaining_weight] = ans;
}

// int knapsack(vector<pair<int,int>> arr,int max_weight,int ind,int remaining_weight){
//     if(remaining_weight==0) return 0; 
//     if(ind<0)return 0;
//     if(remaining_weight<0) return -arr[ind+1].second;
//     int ans=0;
//     ans=max(knapsack(arr,max_weight,ind-1,remaining_weight),knapsack(arr,max_weight,ind-1,remaining_weight-arr[ind].first)+arr[ind].second);
//     return ans;
// }

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
        int  key1;long long int key2;
        cin >> key1 >> key2;
        arr.push_back({key1, key2});
    }
    cout << knapsack(arr.size() - 1, w);
    return 0;
}