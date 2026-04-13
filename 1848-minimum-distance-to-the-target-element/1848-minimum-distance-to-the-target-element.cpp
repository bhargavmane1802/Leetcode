class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int min_distance = nums.size(); // Initialize with maximum possible distance

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                // Calculate absolute distance and update min_distance
                int current_distance = std::abs(i - start);
                
                if (current_distance < min_distance) {
                    min_distance = current_distance;
                }
                
                // Optional optimization: If distance is 0, we found the best possible result
                if (min_distance == 0) return 0;
            }
        }
        
        return min_distance;
    }
};