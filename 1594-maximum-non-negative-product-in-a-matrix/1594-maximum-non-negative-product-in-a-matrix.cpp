class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n, {0, 0}));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]={grid[0][0],grid[0][0]};
                }
                else if(i==0){
                    long long mn=1;
                    long long mx=1;
                    mn=min(grid[i][j] * dp[i][j-1].first , grid[i][j]*dp[i][j-1].second);
                    mx=max(grid[i][j] * dp[i][j-1].first , grid[i][j]*dp[i][j-1].second);
                    dp[i][j]={mx,mn};
                }
                else if(j==0){
                    long long mn=1;
                    long long mx=1;
                    mn=min(grid[i][j] * dp[i-1][j].first , grid[i][j]*dp[i-1][j].second);
                    mx=max(grid[i][j] * dp[i-1][j].first , grid[i][j]*dp[i-1][j].second);
                    dp[i][j]={mx,mn};
                }
                else{
                    long long mn=1;
                    long long mx=1;
                    mn=min(min(grid[i][j] * dp[i][j-1].first , grid[i][j]*dp[i][j-1].second),min(grid[i][j] * dp[i-1][j].first , grid[i][j]*dp[i-1][j].second)); 
                   mx=max(max(grid[i][j] * dp[i][j-1].first , grid[i][j]*dp[i][j-1].second),max(grid[i][j] * dp[i-1][j].first , grid[i][j]*dp[i-1][j].second)); 
                    dp[i][j]={mx,mn};

                }
            }
        }
        
        if(dp[m-1][n-1].first<0)return -1;
        long long mod =1e9+7;
        return dp[m-1][n-1].first %mod;
        
    }
};