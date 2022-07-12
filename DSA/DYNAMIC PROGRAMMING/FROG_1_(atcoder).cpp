#include <bits/stdc++.h>
using namespace std;
int const N=1e5+10;
vector<int> dp(N,-1);

int cost(int arr[],int n,int i=0){
    if(dp[i]!=-1){
        return dp[i];
    }
    if(i==n-1){
        return 0;
    }
    if(i==n-2){
        return abs(arr[i]-arr[i+1]);
    }
    return dp[i]=min(cost(arr,n,i+1)+abs(arr[i]-arr[i+1]),cost(arr,n,i+2)+abs(arr[i]-arr[i+2]));
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<cost(arr,n);
    return 0;
}