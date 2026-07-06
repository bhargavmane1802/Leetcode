class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
    if (a[0] != b[0])
        return a[0] < b[0];
    return a[1] > b[1];
});
        vector<vector<int>>nums;
        nums.push_back(intervals[0]);
        int c=0;
        for(int i=1;i<n;i++){
            if(nums[c][0]<=intervals[i][0] && nums[c][1]>=intervals[i][1]){
                continue;
            }
            else{ nums.push_back(intervals[i]);c++;}
        }
    return nums.size();
    }
};