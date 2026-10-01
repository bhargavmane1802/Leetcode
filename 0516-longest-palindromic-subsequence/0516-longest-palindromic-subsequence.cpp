class Solution {
public:
    int solve(string &s,int l,int r,vector<vector<int>>&dp){
        if(l>r){
            return 0;
        }
        if(l==r)return 1;
        if (dp[l][r]!=-1)return dp[l][r];
        if(s[l]==s[r]){
            return dp[l][r]= 2+solve(s,l+1,r-1,dp);
        }
        else{
            return dp[l][r]=max(solve(s,l+1,r,dp),solve(s,l,r-1,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp);
    }
};