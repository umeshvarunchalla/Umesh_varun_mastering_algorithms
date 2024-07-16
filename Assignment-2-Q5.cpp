// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,a,b,c;
    cin>>n>>m;
    vector<vector<pair<int,int>>> v(n);
    for(int i=0;i<m;i++) {
        cin>>a>>b>>c;
        v[a-1].push_back({c,b-1});
    }
    vector<long int> d(n,LONG_MAX);
    d[0]=0;
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
    pq.push({0, 0});
    long dis,adj_w;
    int ver,adj_v;
    while (!(pq.empty())){
        dis = pq.top().first;
        ver = pq.top().second;
        pq.pop();
        if(dis>d[ver]) continue;
        for (auto it : v[ver]){
            adj_v=it.second;
            adj_w=it.first;
            if (dis+adj_w<d[adj_v]){
                d[adj_v]=dis+adj_w;
                pq.push({dis+adj_w, adj_v});
            }
        }
    }
    for(int i=0;i<n;i++) cout<<d[i]<<" ";
    return 0;
}