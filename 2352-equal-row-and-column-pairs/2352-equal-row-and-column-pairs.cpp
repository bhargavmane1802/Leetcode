class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp1;
        map<vector<int>,int>mp2;
        for(auto i:grid){
            mp1[i]++;
        }
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
            mp2[temp]++;
        }
        int ans=0;
        for(auto x:mp1){
            ans+=(mp1[x.first]*mp2[x.first]);
        }
        return ans;
    }
};