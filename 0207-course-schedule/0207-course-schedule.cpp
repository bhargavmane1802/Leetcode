class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>temp(n,0);
        vector<vector<int>>adj(n);
        for(auto x:pre){
            temp[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(temp[i]==0){q.push(i);
            }
        }
        while(!q.empty()){
            int t= q.front();
            q.pop();
            for(auto x:adj[t]){temp[x]--;
            if(temp[x]==0)q.push(x);}

        }
        for(int i:temp){
            if(i!=0)return false;
        }
        return true;
    }
};