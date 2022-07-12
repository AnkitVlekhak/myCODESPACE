#include <bits/stdc++.h>
#include <climits>
using namespace std;
int dp[310][5010];
int n;
// int coinChange11(vector<int> &coins, int x,int ind)
// {
//     if (x == 0)
//     {
//         return 1;
//     }
//     if(ind<0) {

//         return 0;
//     }
//     if(dp[ind][x]!=-1) return dp[ind][x];
//     int ans=0;
//     for(int i=0;i<=x;i=i+coins[ind]){
//         if(x-i>=0)
//         ans+=coinChange11(coins,x-i,ind-1);
//     }
//     return dp[ind][x]=ans;
// }

int coinChange11(vector<int> &coins, int x, int ind)
{
    if (x == 0)
    {
        return 1;
    }
    if (ind >= n)
    {
        return 0;
    }
    // if(dp[ind][x]!=-1) return dp[ind][x];
    int ans = 0;
    for (int i = 0; i <= x; i = i + coins[ind])
    {
        if (x - i >= 0){
            cout<<ans<<endl;
            ans += coinChange11(coins, x - i, ind + 1);
        }
    }
    // dp[ind][x]=
    return ans;
}
int coinChange(vector<int> &coins,int x){
    memset(dp,-1,sizeof(dp));
    return coinChange11(coins,x,coins.size()-1);

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x;
    cin >> x;
    vector<int> coins;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        coins.push_back(key);
    }
    cout<<coinChange(coins, x);
    return 0;
}