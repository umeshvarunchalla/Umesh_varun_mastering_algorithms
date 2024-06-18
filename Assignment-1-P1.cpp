#include<bits/stdc++.h>
using namespace std;
int min_max_inarray(vector<int> &v,int m,long int k){
    long long cost=0;
    for(int i=0;i<v.size();i++){
        if(v[i]>m){
            cost+=(((long)v[i]*(v[i]+1))/2-((long)m*(m+1))/2);
        }
        if(cost>k) return 0;
    }
    return 1;
}
int main()
{   
    int t,n,l,r;
    long int k,m;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        l=0;
        r=v[v.size()-1];
        n=r;
        while(l<=r){
            m=(r+l)/2;
            if(min_max_inarray(v,m,k)){
                r=m-1;
                n=m;
            }
            else l=m+1;
        }
        cout<<n<<endl;
    }
    return 0;
}