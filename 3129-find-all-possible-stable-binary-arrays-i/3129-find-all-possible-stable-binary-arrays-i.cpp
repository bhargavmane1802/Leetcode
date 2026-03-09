class Solution {
public:
    int limit_val;
    long long MOD = 1e9 + 7;
    // memo[zeros_left][ones_left][last_placed]
    int memo[201][201][2];

    int solve(int z, int o, int last) {
        if (z == 0 && o == 0) return 1;
        if (memo[z][o][last] != -1) return memo[z][o][last];

        long long ans = 0;
        if (last == 0) {
            // Last was 0, so we MUST place some 1s now.
            // We can place k ones, where 1 <= k <= min(limit, o)
            for (int k = 1; k <= min(limit_val, o); ++k) {
                ans = (ans + solve(z, o - k, 1)) % MOD;
            }
        } else {
            // Last was 1, so we MUST place some 0s now.
            // We can place k zeros, where 1 <= k <= min(limit, z)
            for (int k = 1; k <= min(limit_val, z); ++k) {
                ans = (ans + solve(z - k, o, 0)) % MOD;
            }
        }

        return memo[z][o][last] = (int)ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        limit_val = limit;
        for(int i=0; i<=zero; ++i)
            for(int j=0; j<=one; ++j)
                memo[i][j][0] = memo[i][j][1] = -1;

        // We can start with either a block of 0s or a block of 1s
        long long total = 0;
        
        // Starting with k zeros
        for (int k = 1; k <= min(limit, zero); ++k) {
            total = (total + solve(zero - k, one, 0)) % MOD;
        }
        // Starting with k ones
        for (int k = 1; k <= min(limit, one); ++k) {
            total = (total + solve(zero, one - k, 1)) % MOD;
        }

        return (int)total;
    }
};