class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        int ans=INT_MAX;
        for(auto x:roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        queue<pair<int,int>>q;
        q.push({INT_MAX,1});
        vector<int>visited(n+1,-1);
        visited[1]=1;
        while(!q.empty()){
            auto x=q.front();
            int psum=x.first;
            int node=x.second;
            q.pop();
            for(auto a :adj[node]){
                int to =a.first;
                int val=a.second;
                ans=min(ans,min(val,psum));
                if(visited[to]==-1){
                    visited[to]=1;
                    q.push({min(val,psum),to});
                }
            }
        }
    return ans;
    }
};