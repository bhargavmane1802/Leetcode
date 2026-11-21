class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>visited(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        visited[k]=0;
        vector<vector<vector<int>>>adj(n+1);
        for(auto x:times){
            adj[x[0]].push_back({x[2],x[1]});
        }
        while(!q.empty()){
            int x=q.top().first;
            int y=q.top().second;
            q.pop();
            for(auto ele:adj[y]){
                int cost=x+ele[0];
                if(visited[ele[1]]<=cost)continue;
                visited[ele[1]]=cost;
                q.push({cost,ele[1]});
            }
        }
        int ans=0;
        for(int i=1;i<n+1;i++){
            if(visited[i]==INT_MAX)return -1;
            ans=max(ans,visited[i]);
        }
        return ans;
    }
};