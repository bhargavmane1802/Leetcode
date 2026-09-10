class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>>adj(n);
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<pair<int,int>>visited(n,{INT_MAX,k+1});
        queue<pair<int,vector<int>>>q;
        q.push({0,{src,-1}});
        visited[src]={0,0};
        while(!q.empty()){
            auto cost =q.front().first;
            auto from=q.front().second[0];
            auto nv=q.front().second[1];
            q.pop();
            if(from==dst)continue;
            if(nv==k){
                continue;
            }
            for(auto x:adj[from]){
                int to=x[0];
                int fees=x[1]+cost;
                if(visited[to].first>fees || visited[to].second>nv+1){
                    visited[to]={min(visited[to].first,fees),min(visited[to].second,nv+1)};
                    q.push({fees,{to,nv+1}});
                }
            }
        }
        if(visited[dst].first==INT_MAX)return -1;
        return visited[dst].first;
    }
};