#include <bits/stdc++.h>
#include<climits>
using namespace std;
int const N=1e5+10;
vector<int> dp(N,-1);
int n;
int k;

int tcost(int arr[],int i=0){
    int cost=INT_MAX;
    if(dp[i]!=-1){
        return dp[i];
    }
    if(i==n-1){
        return 0;
    }
    if(i==n-2){
        return abs(arr[i]-arr[i+1]);
    }
    for(int j=1;j<k+1;j++){
        if(i+j<n)
        cost=min(cost,tcost(arr,i+j)+abs(arr[i]-arr[i+j]));
    }
    dp[i]=cost;
    return cost;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
    cin>>n;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<tcost(arr)<<endl;
    return 0;
}