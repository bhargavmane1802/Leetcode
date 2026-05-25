class Solution {
public:
    void bfs(vector<vector<char>>& nums,int l,int r,vector<int>&row,vector<int>&col,int n,int m){
        queue<pair<int,int>>q;
        q.push({l,r});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int r=row[i]+x;
                int c=col[i]+y;
                if(r>=0 && c>=0 && r<n && c<m && nums[r][c]=='1'){
                    q.push({r,c});
                    nums[r][c]=0;
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        vector<int>row{0,0,1,-1};
        vector<int>col{1,-1,0,0};
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    grid[i][j]=0;
                    bfs(grid,i,j,row,col,n,m);   
                }
            }
        }
        return ans;
    }
};