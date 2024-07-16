class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b) {
        return a[1]<b[1];
    }

    int scheduleCourse(vector<vector<int>>& c) {
        sort(c.begin(),c.end(),compare);
        int t=0,n=c.size();
        int a=0;
        priority_queue<int> p;
        for(int i=0;i<n;i++){
            p.push(c[i][0]);
            a+=c[i][0];
            if(a>c[i][1]){
                a-=p.top();
                p.pop();
            }
            t=max(t,int(p.size()));
        }
        return t;
    }
};