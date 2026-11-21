class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>in(n);
        vector<vector<int>>adj(n);
        int ans=0;
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
            in[x[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0){q.push(i);ans++;}
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto y:adj[x]){
                in[y]--;
                if(in[y]==0){q.push(y);ans++;}
            }
        }
        if(ans==n)return true;
        return false;
    }
};