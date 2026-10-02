class Solution {
public:
    int solve(vector<int>&nums,int l,int r ,vector<vector<int>>&dp){
        if(l>r)return 0 ;
        if(l==r)return nums[l];
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=0;
        int a=nums[l]*nums[r];
        for(int i=l+1;i<r;i++){
            int b=(a*nums[i])+solve(nums,l,i,dp)+solve(nums,i,r,dp);
            ans=max(ans,b);
        }
        return dp[l][r]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n+2);
        for(int i=0;i<n;i++){
            temp[i+1]=nums[i];
        }
        temp[0]=1;
        temp[n+1]=1;
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return solve(temp,0,n+1,dp);
    }
};