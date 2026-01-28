class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(m, vector<int>(n, 1e9)));
        dp[0][0][0] = 0;
        const int MAX_VAL = 10005;
        
        for (int step = 0; step <= k; ++step) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i > 0) {
                        dp[step][i][j] = min(dp[step][i][j], dp[step][i-1][j] + grid[i][j]);
                    }
                    if (j > 0) {
                        dp[step][i][j] = min(dp[step][i][j], dp[step][i][j-1] + grid[i][j]);
                    }
                }
            }
            
            if (step < k) {
                vector<int> min_cost_for_val(MAX_VAL, 1e9);
                
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        int val = grid[i][j];
                        min_cost_for_val[val] = min(min_cost_for_val[val], dp[step][i][j]);
                    }
                }
                for (int v = MAX_VAL - 2; v >= 0; --v) {
                    min_cost_for_val[v] = min(min_cost_for_val[v], min_cost_for_val[v + 1]);
                }
                
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        int val = grid[i][j];
                       
                        dp[step + 1][i][j] = min(dp[step + 1][i][j], min_cost_for_val[val]);
                    }
                }
            }
        }
        
       
        int result = 1e9;
        for (int step = 0; step <= k; ++step) {
            result = min(result, dp[step][m - 1][n - 1]);
        }
        
        return result;
    }
};