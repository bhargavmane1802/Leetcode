class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,m;
        while(l<=r){
            m=l+(r-l)/2;
            // cout<<m<<" "<<nums[m]<<endl;
            if(nums[m]==target)return m;
            else if((nums[l]<nums[m] && nums[m]>target && nums[l]<=target) || (nums[l]>nums[m] && (nums[m]>target || nums[r]<target)))r=m-1;
            else l=m+1;
        }
        return -1;
    }
};