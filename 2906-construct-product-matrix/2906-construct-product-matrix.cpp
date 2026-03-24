class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mod = 12345;
        vector<vector<int>> p(n, vector<int>(m));
        
        long long currentProduct = 1;

        // Step 1: Fill p with Prefix Products
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[i][j] = currentProduct;
                currentProduct = (currentProduct * (grid[i][j] % mod)) % mod;
            }
        }

        currentProduct = 1; // Reset for suffix

        // Step 2: Multiply p by Suffix Products
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = (p[i][j] * currentProduct) % mod;
                currentProduct = (currentProduct * (grid[i][j] % mod)) % mod;
            }
        }

        return p;
    }
};