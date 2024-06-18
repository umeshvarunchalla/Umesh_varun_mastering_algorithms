#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if((n==1 and m>2)or (m==1 and n>2)) cout<<"-1"<<endl;
    else cout<<(m+n-2+(abs(m-n)/2)*2);
    return 0;
}