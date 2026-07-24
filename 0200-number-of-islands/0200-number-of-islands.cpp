class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<int>row{0,0,1,-1};
        vector<int>col{1,-1,0,0};
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        for(int i=0;i<4;i++){
                            int l=x+row[i];
                            int r=y+col[i];
                            if(l>=0 && r>=0 && l<n && r<m && grid[l][r]=='1'){
                                q.push({l,r});
                                grid[l][r]='0';
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};