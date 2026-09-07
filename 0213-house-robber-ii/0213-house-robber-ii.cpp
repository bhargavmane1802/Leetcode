class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        vector<int>dp=nums;
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++){
            dp[i]=max(dp[i]+dp[i-2],dp[i-1]);
        }
        int ans=dp[n-2];
        dp=nums;
        dp[2]=max(dp[1],dp[2]);
        for(int i=3;i<n;i++){
            dp[i]=max(dp[i]+dp[i-2],dp[i-1]);
        }
        ans=max(ans,dp[n-1]);
        return ans;

    }
};