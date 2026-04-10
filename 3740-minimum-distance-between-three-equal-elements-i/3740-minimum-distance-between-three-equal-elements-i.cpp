class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> index_map;
        for (int i = 0; i < nums.size(); ++i) {
            index_map[nums[i]].push_back(i);
        }
        
        int min_dist = INT_MAX;
        
        // Find the minimum distance among any 3 consecutive occurrences of the same number
        for (const auto& pair : index_map) {
            const vector<int>& indices = pair.second;
            
            // We need at least 3 occurrences to form a valid tuple
            if (indices.size() >= 3) {
                for (int x = 2; x < indices.size(); ++x) {
                    // The simplified distance formula: 2 * (k - i)
                    int current_dist = 2 * (indices[x] - indices[x - 2]);
                    min_dist = min(min_dist, current_dist);
                }
            }
        }
        
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};