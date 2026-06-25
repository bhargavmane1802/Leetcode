class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int cnt = pref[j + 1] - pref[i];
                int len = j - i + 1;
                if (2 * cnt > len)
                    ans++;
            }
        }
        return ans;
    }
};