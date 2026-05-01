class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long n=nums.size();
        long sum=0;
        long temp=0;
        for(int i=0;i<n;i++){
            sum+=(nums[i]*i);
            temp+=nums[i];
        }
        long i=n-1;
        long ans=sum;
        while(i>=0){
            sum=(sum+temp)-(nums[i]*(n));
            ans=max(ans,sum);
            i--;
        }
        return ans;
        
    }
};