#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n,q,t;
    long s=0;
    cin>>n>>q;
    vector<int> v(n),query(q);
    for(int i=0;i<n;i++){
        cin>>v[i];
        s+=v[i];
    }
    for(int i=0;i<q;i++){
        cin>>query[i];
    }
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    for(int i=0;i<n;i++){
        maxheap.push(v[i]);
        minheap.push(v[i]);
    }
    vector<long int> sum(n);
    sum[0]=s;
    for(int i=1;i<n;i++){
        s-=2*minheap.top();
        t=maxheap.top()-minheap.top();
        maxheap.pop();
        minheap.pop();
        maxheap.push(t);
        minheap.push(t);
        sum[i]=s;
    }
    for(int i=0;i<q;i++){
        cout<<sum[query[i]]<<" ";
    }
    return 0;
}