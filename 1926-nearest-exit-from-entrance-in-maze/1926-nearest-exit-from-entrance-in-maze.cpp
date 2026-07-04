class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int n=maze.size();
        int m=maze[0].size();
        vector<int>row{0,0,1,-1};
        vector<int>col{1,-1,0,0};
        int ei=e[0];
        int ej=e[1];
        maze[ei][ej]='+';
        queue<pair<int,int>>q;
        q.push({ei,ej});
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            ans++;
            for(int k=0;k<s;k++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int l=x+row[i];
                    int r=y+col[i];
                    if(l>=0 && r>=0 && l<n && r<m && maze[l][r]=='.'){
                        if(l==0 || r==0 || l==n-1 || r==m-1)return ans;
                        maze[l][r]='+';
                        q.push({l,r});
                    }
                }
            }
        }
        return -1;
    }
};