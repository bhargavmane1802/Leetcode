class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target)return true;
            else if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l++;
                r--;
            }
            else if((nums[l]<nums[mid] && (nums[l]<=target && target<nums[mid]))|| (nums[l]>nums[mid] && (nums[l]<=target || nums[mid]>target))){
                r=mid-1;
            }
            else l=mid+1;
            
        }
        return false;    
    }
};