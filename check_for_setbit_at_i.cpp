#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int> arr;
    int index[n];

    int h=0;
    for(int p=0;p<n;p++){
        int k;cin>>k;
        int c=h;
        index[p]=h;
        for(h;h<k+c;h++){
            int l;cin>>l;
            arr.push_back(l);
        }
    }
    while(q--){
        int i,j;
        cin>>i>>j;
        int r=index[i];
        r=r+j;
        cout<<arr.at(r)<<endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int check(int m,int x){
//     if((m^x)>(m&x)){
//         return 1;
//     }
//     else return 0;
// }
// int main() {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 	    long long int n,q;
// 	    cin>>n;
//         long long int a[n];
// 	    for(long long int i=0;i<n;i++){
//             cin>>a[i];
//         }
//         cin>>q;
//         while(q--){
//             long long int l,r,x,count=0; 
//             cin>>l>>r>>x;
//             for(int i=l-1;i<r;i++){
//                 if(check(a[i],x)){
//                     count++;
//                 }
//             }
//             cout<<count<<endl;
//         }
            
// 	}
// 	return 0;
// }
