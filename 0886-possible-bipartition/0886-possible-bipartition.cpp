class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto x:dislikes){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>visited(n+1,-1);
        queue<int>q;
        for(int i=1;i<n;i++){
            if(visited[i]==-1){
                q.push(i);
                visited[i]=0;
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    int v;
                    if(visited[x]==1)v=0;
                    else v=1;
                    for(int j:adj[x]){
                        if(visited[j]==-1){
                            q.push(j);
                            visited[j]=v;
                        }
                        else if(visited[j]==visited[x])return false;
                    }
                }
            }
        }
        return true;
    }
};