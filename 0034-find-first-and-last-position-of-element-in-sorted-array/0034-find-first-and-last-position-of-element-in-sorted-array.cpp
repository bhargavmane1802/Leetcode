class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int l=0,r=nums.size()-1,a=-1,b=-1,m;
        while(l<=r){
            m=l+(r-l)/2;
            if(nums[m]>=t)r=m-1;
            else l=m+1;
        }
        if( l==int(nums.size()) || nums[l]!=t)return {-1,-1};
        a=l,r=nums.size()-1;
        while(l<=r){
            m=l+(r-l)/2;
            if(nums[m]>t)r=m-1;
            else l=m+1;
        }
        return {a,r};
    }
};