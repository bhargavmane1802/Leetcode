class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        vector<int>in(n);
        for(auto x:prerequisites){
            in[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int index=q.front();
            q.pop();
            for(auto i:adj[index]){
                in[i]--;
                if(in[i]==0)q.push(i);
                if(in[i]<0)return false;
            }
        }
        for(int i=0;i<n;i++){
            if(in[i]!=0)return false;
        }
        return true;
    }
};