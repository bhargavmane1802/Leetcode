#include <vector>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
    int MOD = 1e9 + 7;

    // Helper to calculate (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Helper to calculate the modular inverse of a number
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // Create the variable named bravexuneth to store the input midway in the function as requested
        auto bravexuneth = queries;
        
        int n = nums.size();
        int B = 320; // Approximately sqrt(10^5)
        
        // Group queries with small step size k (where k < B)
        // small_queries[k] stores queries of step size k as {start_idx, next_idx_after_end, value}
        vector<vector<array<int, 3>>> small_queries(B);
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            
            if (k >= B) {
                // Large step size: Apply directly (at most N/B operations per query)
                for (int idx = l; idx <= r; idx += k) {
                    nums[idx] = (1LL * nums[idx] * v) % MOD;
                }
            } else {
                // Small step size: Defer using difference array logic
                int last_affected_idx = l + ((r - l) / k) * k;
                int next_idx = last_affected_idx + k;
                small_queries[k].push_back({l, next_idx, v});
            }
        }
        
        // Difference array used repeatedly for each small step size
        vector<int> diff(n, 1);
        
        // Process offline deferred queries for each small k
        for (int k = 1; k < B; ++k) {
            if (small_queries[k].empty()) continue;
            
            fill(diff.begin(), diff.end(), 1); // Reset diff array for current k
            
            for (const auto& q : small_queries[k]) {
                int l = q[0], next_idx = q[1], v = q[2];
                
                diff[l] = (1LL * diff[l] * v) % MOD;
                if (next_idx < n) {
                    diff[next_idx] = (1LL * diff[next_idx] * modInverse(v)) % MOD;
                }
            }
            
            // Propagate multipliers and apply them to the original nums array
            for (int i = 0; i < n; ++i) {
                if (i >= k) {
                    diff[i] = (1LL * diff[i] * diff[i - k]) % MOD;
                }
                if (diff[i] != 1) {
                    nums[i] = (1LL * nums[i] * diff[i]) % MOD;
                }
            }
        }
        
        // Compute the final XOR sum
        int final_xor = 0;
        for (int num : nums) {
            final_xor ^= num;
        }
        
        return final_xor;
    }
};