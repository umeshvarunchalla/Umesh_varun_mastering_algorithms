#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,c,s;
    vector<vector<int>> a(51,{0,0,0,0,0,0,0,0,0,0,0});
    cin>>n;
    for(int i=0;i<n;i++){
        c=s=0;
        cin>>t;
        while(t!=0){
            s+=(t%10);
            c++;
            t/=10;
        }
        a[s][c-1]++;
    }
    c=0;
    for(int i=0;i<25;i++){
        for(int j=0;j<11;j++){
            c+=(2*a[i][j]*a[50-i][10-j]);
        }
    }
    for(int j=0;j<5;j++){
        c+=(2*a[25][j]*a[25][10-j]);
    }
    c+=a[25][5]*(a[25][5]-1);
    cout<<c<<endl;
    return 0;
}