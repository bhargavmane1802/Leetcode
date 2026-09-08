class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        int n=s.size();
        vector<int>dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int x=s[i-1]-'0';
            if(x>0){
                dp[i]+=dp[i-1];
            }
            if(s[i-2]=='0')continue;
            x=(10 *(s[i-2]-'0'))+x;
            if(x>0 && x<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp.back();

    }
};