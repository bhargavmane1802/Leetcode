class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>temp(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    temp[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<int>row{0,1,0,-1};
        vector<int>col{1,0,-1,0};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            int val=temp[x][y];
            q.pop();
            for(int i=0;i<4;i++){
                int l=row[i]+x;
                int r=col[i]+y;
                if(l>=0 && r>=0 && l<n && r<m && temp[l][r]>val+1 ){
                    temp[l][r]=val+1;
                    q.push({l,r});
                }
            }
        }
        vector<vector<int>>visited(n,vector<int>(m,-1));
        priority_queue<pair<int,pair<int,int>>>qu;
        qu.push({temp[0][0],{0,0}});
        visited[0][0]=temp[0][0];
        while(!qu.empty()){
            auto a=qu.top();
            int x=a.second.first;
            int y=a.second.second;
            int val=a.first;
            qu.pop();
            for(int i=0;i<4;i++){
                int l=row[i]+x;
                int r=col[i]+y;
                if(l>=0 && r>=0 && l<n && r<m){
                    int v=min(temp[l][r],val);
                    if(v>visited[l][r]){
                        visited[l][r]=v;
                        qu.push({v,{l,r}});
                    }
                }
            }
        }
        return visited[n-1][m-1];
        
    return 0;
    }
};