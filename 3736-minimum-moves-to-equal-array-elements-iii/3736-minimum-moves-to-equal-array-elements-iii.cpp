class Solution {
public:
    int minMoves(vector<int>& nums) {
        int m=0;
        for(int i=0;i<nums.size();i++){
            if(nums[m]<nums[i])m=i;
        }
        int ans=0;
        for(int i:nums)ans+=(nums[m]-i);
        return ans;
    }
};