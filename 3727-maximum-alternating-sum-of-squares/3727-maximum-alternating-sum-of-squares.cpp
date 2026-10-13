class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.rbegin(),nums.rend());
        int x=(n+1)/2;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(i<x){
                ans+=(nums[i]*nums[i]);
            }
            else 
            ans-=(nums[i]*nums[i]);
        }
        return ans;
    }
};