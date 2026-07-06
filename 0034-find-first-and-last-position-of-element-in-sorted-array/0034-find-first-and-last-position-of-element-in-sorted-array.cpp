class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)return {-1,-1};
        int l=0;
        int r=nums.size()-1;
        vector<int>ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<target)l=mid+1;
            else r=mid-1;
        }
        if(l<nums.size() && nums[l]==target){
            ans.push_back(l);
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        l=0;r=nums.size()-1;
         while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]<=target)l=mid+1;
            else r=mid-1;
        }
        ans.push_back(l-1);
        return ans;
    }
};