class Solution {
public:
   int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>visited(n,INT_MAX);
        priority_queue<pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>>q;
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        q.push({0,{0,src}});
        visited[src]=0;
        while(!q.empty()){
            auto x=q.top();
            q.pop();
            int to=x.second.second;
            int cost=x.second.first;
            int step=x.first;
            if(step>k)continue;
            for(auto i:adj[to]){
                if(visited[i.first]>=cost+i.second){
                    visited[i.first]=cost+i.second;
                    q.push({step+1,{cost+i.second,i.first}});
                }
            }

        }
        if(visited[dst]==INT_MAX)return -1;
        return visited[dst];
    } 
};