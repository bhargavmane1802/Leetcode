class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>visited(n+1,-1);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto x:times){
            adj[x[0]].push_back({x[2],x[1]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        visited[k]=0;
        while(!q.empty()){
            int wt=q.top().first;
            int from=q.top().second;
            q.pop();
            for(auto x:adj[from]){
                int cost=wt+x.first;
                int to=x.second;
                if(visited[to]==-1){
                    q.push({cost,to});
                    visited[to]=cost;
                }
                else if( visited[to]>cost){
                    q.push({cost,to});
                    visited[to]=cost;
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(visited[i]==-1)return -1;
            ans=max(ans,visited[i]);
        }
        return ans;

    }
};