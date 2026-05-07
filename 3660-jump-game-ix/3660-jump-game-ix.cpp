#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> maxValue(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};
        
        // Step 1: Build prefix maximums
        std::vector<int> pref_max(n);
        pref_max[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pref_max[i] = std::max(pref_max[i - 1], nums[i]);
        }
        
        // Step 2: Build suffix minimums
        std::vector<int> suff_min(n);
        suff_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suff_min[i] = std::min(suff_min[i + 1], nums[i]);
        }
        
        std::vector<int> ans(n);
        int start = 0;
        
        // Step 3: Find cuts and fill the answer array
        for (int i = 0; i < n; ++i) {
            // A cut happens if the max so far is <= the min of the rest of the array.
            // We also forcefully cut at the very last element.
            if (i == n - 1 || pref_max[i] <= suff_min[i + 1]) {
                
                // The maximum of the current block is pref_max[i]
                int block_max = pref_max[i];
                
                // Assign this max to all elements in the current component
                for (int j = start; j <= i; ++j) {
                    ans[j] = block_max;
                }
                
                // Move the start pointer for the next component
                start = i + 1;
            }
        }
        
        return ans;
    }
};