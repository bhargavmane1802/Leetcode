class Solution {
public:
    bool isSorted(const std::vector<int>& nums) {
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!isSorted(nums)) {
            int minSum = INT_MAX;
            int targetIdx = -1;

            for (int i = 0; i < (int)nums.size() - 1; ++i) {
                int currentSum = nums[i] + nums[i + 1];
                if (currentSum < minSum) {
                    minSum = currentSum;
                    targetIdx = i;
                }
            }

            nums[targetIdx] = minSum;
            nums.erase(nums.begin() + targetIdx + 1);
            
            operations++;
        }

        return operations;
    }
};