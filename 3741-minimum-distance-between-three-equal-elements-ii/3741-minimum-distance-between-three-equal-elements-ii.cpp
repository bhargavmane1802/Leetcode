class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx1(n + 1, -1);
        vector<int> idx2(n + 1, -1);
        
        int min_dist = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            if (idx1[val] != -1) {
                min_dist = min(min_dist, 2 * (i - idx1[val]));
            }
            idx1[val] = idx2[val];
            idx2[val] = i;
        }
        
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};