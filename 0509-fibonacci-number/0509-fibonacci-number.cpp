class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==0)return 0;
        if(n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int x=solve(n-1,dp)+solve(n-2,dp);
        dp[n]=x;
        return x;
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};