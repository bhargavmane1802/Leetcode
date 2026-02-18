class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int>degree(n,0);
        int m=0;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            degree[i[1]]++;
            degree[i[0]]++;
        }
        unordered_set<int>store;
        while(true){
            vector<int>temp;
            for(int i=0;i<n;i++){
                if(degree[i]==1){temp.push_back(i);}
            }
            if(temp.size()==2 || temp.size()==1)return temp;
            if(temp.size()==0)break;
            for(int i:temp){
                degree[i]--;
                store.insert(i);
                for(auto x:adj[i]){
                    degree[x]--;
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(store.find(i)==store.end())ans.push_back(i);
        }
        return ans;
    }
};