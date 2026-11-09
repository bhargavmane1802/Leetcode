class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>in(n);
        vector<vector<int>>adj(n);
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
            in[x[0]]++;
        }
        int c=0;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0){q.push(i);}
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            c++;
            for(auto j:adj[x]){
                in[j]--;
                if(in[j]==0)q.push(j);
            }
        }
        if(c==n)return true;
        return false;
    }
};