class Solution {
public:
    bool solve(string &s,int l,int r,vector<vector<int>>&dp){
        if(l>r)return true;
        if(l==r){
            if(s[l]=='*')return true;
            return false;
        }
        if(dp[l][r]!=-1)return dp[l][r];
        if((s[l]=='(' ||s[l]=='*') && (s[r]==')' || s[r]=='*') && solve(s,l+1,r-1,dp)) return dp[l][r]=1;
        for(int i=l;i<r;i++){
            if(solve(s,l,i,dp) && solve(s,i+1,r,dp)) return  dp[l][r]=1;
        }

        dp[l][r]=0;
        return false;
        
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(s,0,n-1,dp);
        
    }
};