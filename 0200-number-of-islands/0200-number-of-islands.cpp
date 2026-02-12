class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>&grid,vector<int>&row,vector<int>&col,int &m,int&n){
        for(int i=0;i<4;i++){
            int a=r+row[i];
            int b=c+col[i];
            if(a>=0 && b>=0 && a<m &&b<n && grid[a][b]=='1'){
                grid[a][b]='0';
                dfs(a,b,grid,row,col,m,n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<int>row={0,0,1,-1};
        vector<int>col={1,-1,0,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    grid[i][j]='0';
                    dfs(i,j,grid,row,col,m,n);
                }
            }
        }
        return ans;
    }
};