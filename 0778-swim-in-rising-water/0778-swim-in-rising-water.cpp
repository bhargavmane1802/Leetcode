class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<int>row{0,0,-1,1};
        vector<int>col{1,-1,0,0};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({grid[0][0],{0,0}});
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,INT_MAX));
        visited[0][0]=grid[0][0];
        while(!q.empty()){
            int w=q.top().first;
            int x=q.top().second.first;
            int y=q.top().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int l=row[i]+x;
                int r=col[i]+y;
                if(l>=0 && r>=0 && l<n && r<n ){
                    int a=max(w,grid[l][r]);
                    if(visited[l][r]==INT_MAX){
                        q.push({a,{l,r}}); 
                        visited[l][r]=a;
                    }
                    else if(visited[l][r]>a){
                        q.push({a,{l,r}});
                        visited[l][r]=a;
                    }
                }
            }
        }
        return visited[n-1][m-1];
    }
};