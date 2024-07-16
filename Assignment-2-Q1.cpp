#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin>>n>>x;
    vector<int> c(n);
    int d[n][x+1];
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++) d[i][0]=1;
    for(int j=1;j<=x;j++){
        d[0][j]=0;
        if(j>=c[0]) d[0][j]=d[0][j-c[0]];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=x;j++){
            d[i][j]=0;
            if(j>=c[i]) d[i][j]=(int)(((long)d[i-1][j]+d[i][j-c[i]])%1000000007);
            else d[i][j]=d[i-1][j];
        }
    }
    cout<<d[n-1][x];
    return 0;
}