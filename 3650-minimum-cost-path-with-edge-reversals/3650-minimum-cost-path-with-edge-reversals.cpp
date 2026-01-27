class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]*2});
        }
        vector<int>visited(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,0});
        visited[0]=0;
        while(!q.empty()){
            auto p=q.top();
            q.pop();
            if(p.second==n-1)return p.first;
            for(auto i:adj[p.second]){
                if(visited[i.first]>(p.first+i.second)){
                    visited[i.first]=p.first+i.second;
                    q.push({p.first+i.second,i.first});
                }
            }
        }
        return -1;  
    }
};