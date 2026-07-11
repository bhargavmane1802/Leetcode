class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
     vector<int>visited(n);
     int ans=0;
     vector<vector<int>>adj(n);
     for (auto x:edges){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
     }
     queue<int>q;
     for(int i=0;i<n;i++){
        if(visited[i]==0){
            visited[i]=1;
            q.push(i);
            int vc=1;
            int ec=0;
            while(!q.empty()){
                int v=q.front();
                q.pop();
                for(int j:adj[v]){
                    ec++;
                    if(visited[j]==0){
                        vc++;
                        visited[j]=1;
                        q.push(j);
                    }
                }
            }
            if(ec/2==vc*(vc-1)/2)ans++;
        }
     }
      return ans;
    }
};