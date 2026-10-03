class Solution {
public:
int solve(vector<int>&nums, int l,int r,vector<vector<int>>&dp){
    if(dp[l][r]!=-1)return dp[l][r];
    if(l+1==r)return dp[l][r] =nums[r]-nums[l];
    int ans=INT_MAX;
    for(int i=l+1;i<r;i++){
        ans= min(ans,nums[r]-nums[l] +solve(nums,l,i,dp)+solve(nums,i,r,dp));
    }
    return dp[l][r] =ans;
}
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int s=cuts.size();
        vector<int>nums(s+2);
        vector<vector<int>>dp(s+2,vector<int>(s+2,-1));
        nums[0]=0;
        for(int i=0;i<s;i++){
            nums[i+1]=cuts[i];
        }
        nums[s+1]=n;
        return solve(nums,0,s+1,dp) -n;
    }
};