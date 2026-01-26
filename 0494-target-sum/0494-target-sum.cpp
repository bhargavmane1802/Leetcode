class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int t) {
        int tsum=0;
        int n=nums.size();
        for(int i:nums){
            tsum+=i;
        }
        if(t==abs(tsum)){
            return 1;
        }
        if((tsum+t)%2!=0)return 0;
        int r=(tsum+t)/2;
        vector<int>dp(r+1,0);
        dp[0]=1;
        for(int i:nums){
            for(int j=r;j>=i;j--){
                dp[j]+=dp[j-i];
            }
        }
        return dp[r];
    }
};