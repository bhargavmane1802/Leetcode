class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        vector<int>row{0,0,1,-1};
        vector<int>col={1,-1,0,0};
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int l=x+row[j];
                    int r=y+col[j];
                    if(l>=0 && r>=0 && l<n && r<m && ans[l][r]==-1){
                        q.push({l,r});
                        ans[l][r]=ans[x][y]+1;
                    }
                }
            }
        }
        return ans;
    }
};