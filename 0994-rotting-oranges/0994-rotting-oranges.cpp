class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int>r{0,0,-1,1};
        vector<int>c{1,-1,0,0};
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(q.empty()){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1)return -1;
                }
            }
            return 0;
        }
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            ans++;
                for(int i=0;i<s;i++){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for(int j=0;j<4;j++){
                        int l=x+r[j];
                        int r=y+c[j];
                        if(l>=0 && r>=0 && l<n && r<m && grid[l][r]==1){
                            grid[l][r]=2;
                            q.push({l,r});
                        }
                    }
                }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return ans-1;
    }
};