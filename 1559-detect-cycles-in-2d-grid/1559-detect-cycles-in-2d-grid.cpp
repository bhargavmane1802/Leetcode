class Solution {
public: 
    bool dfs(vector<vector<char>>& grid, vector<vector<int>>&visited,int l,int r, int pl,int pr,vector<int>&v1,vector<int>& v2,int & n ,int & m){
        for(int i=0;i<4;i++){
            int ci=l+v1[i];
            int cj=r+v2[i];
            if(ci>=0 && cj>=0 && ci<n && cj<m && grid[l][r]==grid[ci][cj]){
                if(ci==pl && cj==pr)continue;
                if(visited[ci][cj]==1)return true;
                visited[ci][cj]=1;
                if(dfs(grid,visited,ci,cj,l,r,v1,v2,n,m))return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<int>v1{0,0,1,-1};
        vector<int>v2{1,-1,0,0};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( 0==visited[i][j] ){
                    visited[i][j]=1;
                    if(dfs(grid,visited,i,j,i,j,v1,v2,n,m))return true;
                }
            }
        }
        return false;
        
    }
};