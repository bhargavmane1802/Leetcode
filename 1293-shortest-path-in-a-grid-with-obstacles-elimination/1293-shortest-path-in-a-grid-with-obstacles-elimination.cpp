class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>row{1,-1,0,0};
        vector<int>col{0,0,-1,1};
        vector<vector<pair<int,int>>>visited(n,vector<pair<int,int>>(m,{INT_MAX,k+1}));
        queue<vector<int>>q;
        int ans=INT_MAX;
        if(grid[0][0]==0) q.push({0,0,grid[0][0],0});
        else q.push({0,0,grid[0][0],1});
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int a=t[0],b=t[1],cost=t[2],block=t[3];
            if(block==k+1)continue;
            if(a==n-1 && b==m-1){
                ans=min(ans,cost);
                continue ;
            }
            for(int i=0;i<4;i++){
                int x=a+row[i];
                int y=b+col[i];
                if(x>=0 && y>=0 && x<n && y<m){
                    int fees=cost+1;
                    int bk=block;
                    if(grid[x][y]==1)bk++;
                    if(visited[x][y].first>fees || visited[x][y].second >bk ){
                        visited[x][y].first=min(visited[x][y].first,fees);
                        visited[x][y].second=min(visited[x][y].second,bk);
                        q.push({x,y,fees,bk});
                    }
                }
            }


        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};