class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        queue<int>q;
        vector<int>visited(n);
        int ans=0;
        for(int  i=0;i<n;i++){
            if(visited[i]==0){
                ans++;
                visited[i]=1;
                q.push(i);
                while(!q.empty()){
                    int  t=q.front();
                    q.pop();
                    for(int j=0;j<n;j++){
                        if(visited[j]==0 && adj[t][j]!=0){
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