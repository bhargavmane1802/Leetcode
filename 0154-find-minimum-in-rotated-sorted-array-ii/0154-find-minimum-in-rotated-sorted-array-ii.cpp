class Solution {
public:
    int split(vector<int>&nums,int l,int r){
        if(l+1==r)return min(nums[l],nums[r]); 
        int m=(l+r)/2;
        if(nums[m-1]>nums[m] && nums[m]<nums[m+1])return nums[m];
        else{
            if(nums[l]==nums[r] && nums[l]==nums[m])return min(split(nums,l,m),split(nums,m,r));
            else if(nums[m]>nums[r])return split(nums,m,r);
            else return split (nums,l,m);
        }
    }

    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(nums[0]<nums[n-1])return nums[0];
        if(nums[n-2]>nums[n-1])return nums[n-1];
        int l=0;
        int r=n-1;
        return split(nums,l,r);
    }
};