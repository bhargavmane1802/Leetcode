class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        int ans=0;
        vector<int>visited(n);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                ans++;
                q.push(i);
                visited[i]=1;
                while(!q.empty()){
                    int x=q.front();
                    q.pop();
                    for(int j=0;j<n;j++){
                        if(adj[x][j]==1 && visited[j]==0){
                            q.push(j);
                            visited[j]=1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};