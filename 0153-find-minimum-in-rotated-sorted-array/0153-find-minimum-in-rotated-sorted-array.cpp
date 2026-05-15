class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(1==n)return nums[0];
        if(nums[0]<nums[n-1])return nums[0];
        if(2==n)return nums[1];
        if(nums[n-2]>nums[n-1])return nums[n-1];
        int l=0;
        int r=n-1;
        int m=0;
        while(l+1<r){
            m=(l+r)/2;
            if(nums[m-1]>nums[m] && nums[m]<nums[m+1])return nums[m];
            else if(nums[m]>nums[r])l=m;
            else r=m;
        }
        return nums[m];
    }
};