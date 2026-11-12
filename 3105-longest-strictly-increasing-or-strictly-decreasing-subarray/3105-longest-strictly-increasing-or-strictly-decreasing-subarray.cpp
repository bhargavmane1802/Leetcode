class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1,a=1,b=1,n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i])a++;
            else a=1;
            if(nums[i-1]>nums[i])b++;
            else b=1;
            ans=max(ans,max(a,b));
        }
        return ans;
    }
};