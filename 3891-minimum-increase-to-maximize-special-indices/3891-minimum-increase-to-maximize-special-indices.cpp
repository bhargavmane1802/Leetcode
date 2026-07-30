class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();

        if (n % 2 == 1) {
            long long ans = 0;

            for (int i = 1; i < n - 1; i += 2) {
                ans += max(
                    0LL,
                    (long long)max(nums[i - 1], nums[i + 1]) + 1 - nums[i]
                );
            }

            return ans;
        }

        vector<long long> e;
        vector<long long> o;

        long long evensum = 0;
        long long oddsum = 0;

        for (int i = 1; i < n - 1; i++) {
            long long cost = max(
                0LL,
                (long long)max(nums[i - 1], nums[i + 1]) + 1 - nums[i]
            );

            if (i % 2 == 0) {
                evensum += cost;
                e.push_back(evensum);
            } else {
                oddsum += cost;
                o.push_back(oddsum);
            }
        }

        // Option 1: all even positions
        // Option 2: all odd positions
        long long ans = min(evensum, oddsum);

        int x = o.size();

        // Odd positions first, then even positions.
        //
        // Example:
        // {1} + {4,6}
        // {1,3} + {6}
        // {1,3,5}
        //
        for (int i = 0; i < x; i++) {
            ans = min(ans, o[i] + evensum - e[i]);
        }

        return ans;
    }
};