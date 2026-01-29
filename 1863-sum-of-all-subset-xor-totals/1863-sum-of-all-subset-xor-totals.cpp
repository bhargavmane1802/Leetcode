class Solution {
public:
    int subsetXORSum(std::vector<int>& nums) {
        int bitwiseOR = 0;
        for (int x : nums) {
            bitwiseOR |= x;
        }
        return bitwiseOR * (1 << (nums.size() - 1));
    }
};