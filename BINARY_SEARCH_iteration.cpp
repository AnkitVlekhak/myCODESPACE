#include<iostream>
using namespace std;

int binary(int arr[],int n,int key){
    int s=0,e=n;
    for(int i=0;i<n;i++){
        int mid=(s+e)/2;
        if(key==arr[mid]){
            return mid;
        }
        else if(key<arr[mid]){
            e=mid;
        }
        else{
            s=mid;
        }
    }
}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;cin>>k;
    cout<<binary(arr,n,k);
    return 0;
}