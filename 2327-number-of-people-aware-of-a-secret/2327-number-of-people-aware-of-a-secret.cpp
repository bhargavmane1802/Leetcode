class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long ans=0;
        long long mod=1e9 +7;
        vector<long long>nums(n);
        nums[0]=1;
        for(int i=0;i<n;i++){
            for(int j=i+delay ; j<n && j<i+forget ;j++){
                nums[j]=(nums[j]+nums[i])%mod;
            }
        }
        int s =max(0,n-forget);
         for (int i=s;i<n;i++) {
            ans=(ans+nums[i])%mod;
        }
        return ans;

    }
};