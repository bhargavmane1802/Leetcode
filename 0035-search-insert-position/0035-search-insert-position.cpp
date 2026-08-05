class Solution {
public:
    int searchInsert(vector<int>& nums, int t) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(t==nums[m])return m;
            else if(nums[m]>t)r=m-1;
            else l=m+1;
        }
        return l;
    }
};