class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i:nums)sum+=i;
        if(sum%2!=0)return false;
        sum/=2;
        vector<int>dp(sum+1);
        dp[0]=1;
        for(int i:nums){
            if(i>sum)continue;
            for(int j=sum;j>=0+i;j--){
                if(dp[j-i]==1)dp[j]=1;
            }
        }
        return dp.back()==1;

        
    }
};