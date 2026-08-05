class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int t) {
        int n=nums.size();
        int m=nums[0].size();
        if(t<nums[0][0] || t>nums[n-1][m-1])return false;
        int l=0;
        int r=m-1;
        while(l<n && r>=0){
            int mid=l+(r-l)/2;
            if(nums[l][r]==t)return true;
            else if(nums[l][r]>t)r--;
            else l++;
        }
        return false;
    }
};