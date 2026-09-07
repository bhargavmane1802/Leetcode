class Solution {
public:
int solve(int i,vector<int>&nums,vector<int>&dp,int n){
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
    dp[i]=max(nums[i]+solve(i+2,nums,dp,n),solve(i+1,nums,dp,n));
    return dp[i];
}
    int rob(vector<int>& nums) {

        int n=nums.size();
        vector<int>dp(n,-1);
        vector<int>dp1(n,-1);
        
        return max(nums[0]+solve(2,nums,dp,n-1),solve(1,nums,dp1,n));
    }
};