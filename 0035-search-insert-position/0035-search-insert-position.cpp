class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int mid=(l+r)/2;
            if(nums[mid]==target)return mid;
            if(nums[mid]>target)r=mid;
            else l=mid+1;
        }
        if(l==nums.size()-1 && nums[l]<target)return l+1;
        return l; 

    }
};