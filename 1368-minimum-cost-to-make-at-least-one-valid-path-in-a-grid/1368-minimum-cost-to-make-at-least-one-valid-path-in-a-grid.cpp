class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1 && m==1)return 0;
        vector<vector<int>>visited(n,vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
        q.push({0,0,0});
        visited[0][0]=0;
        vector<int>row{0,0,1,-1};
        vector<int>col{1,-1,0,0};
        while(!q.empty()){
            auto [cost,a,b]=q.top();
            q.pop();
            if(a==n-1 && b==m-1)return cost;
            if(cost != visited[a][b])continue;
            for(int i=0;i<4;i++){
                int x=a+row[i];
                int y=b+col[i];
                if(x>=0 && y>=0 && x<n && y<m){
                    int c=cost;
                    if(i+1!=grid[a][b])c++;
                    if(visited[x][y]>c){
                        visited[x][y]=c;
                        q.push({c,x,y});
                    }
                }
            }

        }
        return -1;
    }
};