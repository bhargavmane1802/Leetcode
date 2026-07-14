class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp1;
        for(auto i:grid){
            mp1[i]++;
        }
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
            ans+=mp1[temp];
        }
        
        return ans;
    }
};