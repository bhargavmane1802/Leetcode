class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int>inorder(n);
        vector<int>visited(n,-1);
        vector<vector<int>>adj(n);
        for(auto x:p){
            adj[x[1]].push_back(x[0]);
            inorder[x[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inorder[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
        while(!q.empty()){
            int t=q.front();
            q.pop();
            for(auto x: adj[t]){
                inorder[x]--;
                if(inorder[x]==0){
                    q.push(x);
                    visited[x]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(visited[i]==-1)return false;
        }
        return true;
    }
};