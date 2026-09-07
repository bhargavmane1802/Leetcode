class Solution {
public:
    int solve(string & s,int i,vector<int>&dp){
        if(i==(int)s.size())return 1;
        if(s[i]=='0')return 0;
        if(i==s.size()-1)return 1;
        if(dp[i]!=-1)return dp[i];
        int x= s[i]-'0';
        int y=s[i+1]-'0';
        x=(x*10)+y;
        int ans=0;
        if(x>0 && x<27){
            ans=solve(s,i+2,dp);
        }
        ans+=solve(s,i+1,dp);
        dp[i]=ans;
        return ans;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
       return solve(s,0,dp);
    }
};