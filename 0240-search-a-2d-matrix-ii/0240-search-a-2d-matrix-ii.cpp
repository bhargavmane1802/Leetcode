class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int t) {
        int n=nums.size();
        int m=nums[0].size();
        if(t<nums[0][0] || t>nums[n-1][m-1])return false;
        for(int i=0;i<n;i++){
            int l=0;
            int r=m-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums[i][mid]==t)return true;
                else if(nums[i][mid]>t)r=mid-1;
                else l =mid+1;
            }
        }
        return false;
    }
};