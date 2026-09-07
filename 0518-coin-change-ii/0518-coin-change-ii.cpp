class Solution {
public:
    int change(int a, vector<int>& coins) {
        long long mod=1e10;
        vector<long long>nums(a+1);
        nums[0]=1;
        for(int i:coins){
            for(int j=0;j<=a-i;j++){
                nums[j+i]=(nums[j+i]+nums[j])%mod;
            }
        }
        return nums.back();
    }
};