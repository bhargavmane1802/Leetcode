class Solution {
public:
    int solve(vector<int>&nums,int t,int s,vector<int>&dp){
        if(s==t)return 1;
        if(s>t)return 0;
        if(dp[s]!=-1)return dp[s];
        int ans=0;
        for(int i:nums){
            ans+=solve(nums,t,s+i,dp);
        }
        return dp[s]= ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return solve(nums,target,0,dp);
    }
};