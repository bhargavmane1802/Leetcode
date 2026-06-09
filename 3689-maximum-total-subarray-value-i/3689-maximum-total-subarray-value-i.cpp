class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mx=0;
        long long mn=0;
        for(long long i=0;i<nums.size();i++){
           if(nums[i]>nums[mx])mx=i;
           if(nums[i]<nums[mn])mn=i;
        }
         return 1LL * k * (nums[mx] - nums[mn]);;
    }
};