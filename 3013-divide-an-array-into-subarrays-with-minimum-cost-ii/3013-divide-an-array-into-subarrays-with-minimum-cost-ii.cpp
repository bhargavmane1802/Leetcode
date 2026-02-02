class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int d) {
        long long ans = 1000000000;

        multiset<long long> small;
        multiset<long long> large;
        long long sum = 0;
        for (int i = 1; i <= d+1; i++) {
            large.insert(nums[i]);
        }
        while (small.size() < k - 1) {
            small.insert(*large.begin());
            sum += *large.begin();
            large.erase(large.begin());
        }
        ans = sum ;
        int n = nums.size();
        for (int i = 2; i < n - d; i++) {

            if (*small.rbegin() > nums[i + d ]) {
                small.insert(nums[i + d ]);
                sum += nums[i + d ];
                large.insert(*small.rbegin());
                sum -= *small.rbegin();
                small.erase(prev(small.end()));
            } else {
                large.insert(nums[i + d ]);
            }
            if (small.find(nums[i - 1]) != small.end()) {
                sum -= nums[i - 1];
                small.erase(small.find(nums[i - 1]));
                small.insert(*large.begin());
                sum += *large.begin();
                large.erase(large.begin());
            } else {
                large.erase(large.find(nums[i - 1]));
            }
            ans = min(sum , ans);
        }

        return ans + nums[0];
    }
};