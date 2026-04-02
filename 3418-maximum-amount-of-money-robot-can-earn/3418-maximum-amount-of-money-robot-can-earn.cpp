class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        // A sufficiently small value to represent unreachable states, 
        // safe from integer underflow when adding negative coins.
        const int INF = 1e9; 
        
        // dp[i][j][k] = max profit at (i, j) using exactly k neutralizations
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -INF)));
        
        // Base case: Starting position (0, 0)
        dp[0][0][0] = coins[0][0];
        if (coins[0][0] < 0) {
            dp[0][0][1] = 0; // Use 1 neutralization on the start cell if it's a robber
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue; // Skip the already-initialized starting cell
                
                for (int k = 0; k <= 2; ++k) {
                    int val = -INF;
                    
                    // Coming from the TOP cell
                    if (i > 0) {
                        // Option 1: Take the cell's value (positive or negative)
                        if (dp[i-1][j][k] != -INF) {
                            val = max(val, dp[i-1][j][k] + coins[i][j]);
                        }
                        // Option 2: Neutralize the cell (valid only if it's a robber and we used a neutralization)
                        if (coins[i][j] < 0 && k > 0 && dp[i-1][j][k-1] != -INF) {
                            val = max(val, dp[i-1][j][k-1]); 
                        }
                    }
                    if (j > 0) {
                        // Option 1: Take the cell's value
                        if (dp[i][j-1][k] != -INF) {
                            val = max(val, dp[i][j-1][k] + coins[i][j]);
                        }
                        // Option 2: Neutralize the cell
                        if (coins[i][j] < 0 && k > 0 && dp[i][j-1][k-1] != -INF) {
                            val = max(val, dp[i][j-1][k-1]);
                        }
                    }
                    
                    dp[i][j][k] = val;
                }
            }
        }
        
        // Return the max profit across all possible combinations of neutralizations used (0, 1, or 2)
        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};