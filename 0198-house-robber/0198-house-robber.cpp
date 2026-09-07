class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        if(i>=(int)nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]= nums[i]+max(solve(i+2,nums,dp),solve(i+3,nums,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size()+1;
        vector<int>dp(n,-1);
        return max(solve(0,nums,dp),solve(1,nums,dp));
    }
};