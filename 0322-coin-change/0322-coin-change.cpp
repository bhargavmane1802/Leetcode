class Solution {
public:
    int coinChange(vector<int>& coins, int a) {
        vector<int>dp(a+1,a+1);
        dp[0]=0;
        for(int i=1;i<a+1;i++){
            for(int coin:coins){
                if((i-coin)>=0){
                    dp[i]=min(dp[i],dp[i-coin]+1);
                }
            }
        }
        return dp[a] > a ? -1 : dp[a];
    }
};