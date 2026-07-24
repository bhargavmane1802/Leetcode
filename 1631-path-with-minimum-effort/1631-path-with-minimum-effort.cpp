class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        vector<vector<int>>visited(n,vector<int>(m,INT_MAX));
        vector<int>row{0,0,1,-1};
        vector<int>col{1,-1,0,0};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        visited[0][0]=0;
        while(!q.empty()){
            auto a=q.top();
            q.pop();
            int val=a.first;
            int x=a.second.first;
            int y=a.second.second;
            for(int i=0;i<4;i++){
                int l=x+row[i];
                int r=y+col[i];
                if(l>=0 && r>=0 && l<n && r<m){
                    int data=max(val,abs(h[x][y]-h[l][r]));
                    if(visited[l][r]>data){
                        q.push({data,{l,r}});
                        visited[l][r]=data;
                    }
                }
            }
        }
        return visited[n-1][m-1];
    }
};