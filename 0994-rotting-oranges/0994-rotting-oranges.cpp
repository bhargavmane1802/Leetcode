class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        queue<vector<int>>q;
        int ans=-1;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)fresh++;
                else if(grid[i][j]==2)q.push({i,j});
            }
        }
        if(fresh==0)return 0;
        vector<int>row{0,0,1,-1};
        vector<int>col{1,-1,0,0};
        while(!q.empty()){
            int s=q.size();
            ans++;
            for(int i=0;i<s;i++){
                int l=q.front()[0];
                int r=q.front()[1];
                q.pop();
                for(int j=0;j<4;j++){
                    int x=l+row[j];
                    int y=r+col[j];
                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1){
                        grid[x][y]=2;
                        fresh--;
                        q.push({x,y});

                    }
                }
            }
        }
        if(fresh==0)return ans;
        return -1;
    }
};