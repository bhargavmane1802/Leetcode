class Solution {
public:
    int solve(int i,vector<int>&cost,vector<int>&dp){
        if(i>=(int)cost.size())return 0;
        if(i==-1)return min(solve(i+1,cost,dp),solve(i+2,cost,dp));
        if(dp[i]!=-1)return dp[i];
        return dp[i]=cost[i]+min(solve(i+1,cost,dp),solve(i+2,cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return solve(-1,cost,dp);
    }
};