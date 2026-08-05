class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& arr) {
        vector<vector<int>>adj(n);
        for(auto x:arr){
            adj[x[0]].push_back(x[1]);
        }
        queue<int>q;
        q.push(k);
        vector<int>visited(n,-1);
        visited[k]=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i:adj[x]){
                if(visited[i]==-1){
                    visited[i]=0;
                    q.push(i);
                }
            }
        }
        for(int j=0;j<n;j++){
            if(visited[j]==0)continue;
            if(visited[j]==-1){
                q.push(j);
                visited[j]=1;
                while(!q.empty()){
                int x=q.front();
                q.pop();
                for(int i:adj[x]){
                    if(visited[i]==0){
                        vector<int>ans(n);
                        for(int i=0;i<n;i++){
                            ans[i]=i;
                        }
                        return ans;
                    }
                    if(visited[i]==-1){
                        q.push(i);
                        visited[i]=1;
                    }
                }
            }
            }
        }
        vector<int>ans;
            for(int i=0;i<n;i++){
                if(visited[i]==1)ans.push_back(i);
            }
        return ans;
    }
};