// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int maxbisc(vector<int>& p,vector<int>& b,int n,int k){
    if(n==0 or k==0) return 0;
    //if he has money less than the price of packet we will skip that packet1
    if(k<p[n-1]) return maxbisc(p,b,n-1,k);
    else return max((b[n-1]+maxbisc(p,b,n-1,k-p[n-1])),maxbisc(p,b,n-1,k));
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> oreo_price(n),oreo_bisc(n);
        for(int i=0;i<n;i++) cin>>oreo_price[i]>>oreo_bisc[i];
        //storing price and no.of biscuits in each packet
        cout<<maxbisc(oreo_price,oreo_bisc,n,k)<<endl;
    }
    return 0;
}