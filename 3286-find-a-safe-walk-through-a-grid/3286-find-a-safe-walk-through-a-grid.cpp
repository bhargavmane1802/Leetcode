class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int h) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        visited[0][0]=(h-grid[0][0]);
        queue<pair<int,pair<int,int>>>q;
        if(visited[0][0]>0){
            q.push({visited[0][0],{0,0}});
        }
        vector<int>row{0,0,1,-1};
        vector<int>col{1,-1,0,0};
        while(!q.empty()){
            int val=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int l=row[i]+x;
                int r=col[i]+y;
                if(l>=0 && r>=0 && l<n && r<m && val-grid[l][r]>0 && visited[l][r]<val-grid[l][r]){
                    if(l==n-1 && r==m-1)return true;
                    q.push({val-grid[l][r],{l,r}});
                    visited[l][r]=val-grid[l][r];
                }
            }
        }
        return false;


    }
};