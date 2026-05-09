class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int x=min(n,m)/2;
        vector<vector<int>>nums(x);
        for(int i=0;i<x;i++){
            for(int j=i;j<m-i;j++)nums[i].push_back(grid[i][j]);
            for(int j=i+1;j<n-i;j++)nums[i].push_back(grid[j][m-i-1]);
            for(int j=m-2-i;j>=i;j--)nums[i].push_back(grid[n-1-i][j]);
            for(int j=n-2-i;j>i;j--)nums[i].push_back(grid[j][i]);
        }
        for(int i=0;i<x;i++){
            int t=nums[i].size();
            t=k%t;
            reverse(nums[i].begin(),nums[i].begin()+t);
            reverse(nums[i].begin()+t,nums[i].end());
            reverse(nums[i].begin(),nums[i].end());
            int  c=0;
            for(int j=i;j<m-i;j++){grid[i][j]=nums[i][c];c++;}
            for(int j=i+1;j<n-i;j++){grid[j][m-i-1]=nums[i][c];c++;}
            for(int j=m-2-i;j>=i;j--){grid[n-1-i][j]=nums[i][c];c++;}
            for(int j=n-2-i;j>i;j--){grid[j][i]=nums[i][c];c++;}
        }
        return grid;
    }
};