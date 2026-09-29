class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int p=n+m-1;
        if((p%2)!=0)return false;
        p/=2;
        if(grid[0][0]==')' || grid[n-1][m-1]=='(')return false;
        vector<vector<vector<int>>>visited(n,vector<vector<int>>(m,vector<int>(p+1,0)));
        queue<vector<int>>q;
        q.push({0,0,1});
        visited[0][0][1]=1;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto a=q.front();
                q.pop();
                int x=a[0],y=a[1],z=a[2];
                if(x==n-1 && y==m-1 && z==0)return true;
                if(x<n-1){
                    int cost=z;
                    if(grid[x+1][y]==')')cost--;
                    else cost++;
                    if(cost<0 || cost>p)continue;
                    if(visited[x+1][y][cost]==0){
                        visited[x+1][y][cost]=1;
                        q.push({x+1,y,cost});
                    }
                }
                if(y<m-1){
                    int cost=z;
                    if(grid[x][y+1]==')')cost--;
                    else cost++;
                    if(cost<0 || cost>p)continue;
                    if(visited[x][y+1][cost]==0){
                        visited[x][y+1][cost]=1;
                        q.push({x,y+1,cost});
                    }
                }
            }
        }
        return false;
    }
};