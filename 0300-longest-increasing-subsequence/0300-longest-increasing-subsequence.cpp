class Solution {
public:
    int solve(vector<int>&nums,int idx,vector<int>&dp){
        if(idx>=(int)(nums.size()))return 0;
        int ans=0;
        int x;
        if(idx==-1){
            x=INT_MIN;
        }
        else x=nums[idx];
        if(dp[idx+1]!=-1)return dp[idx+1];
        for(int i=idx+1;i<nums.size();i++){
            if(x<nums[i]){
                ans=max(ans,solve(nums,i,dp));
            }
        }
        return dp[idx+1]=ans+1;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,-1,dp)-1;
        
    }
};