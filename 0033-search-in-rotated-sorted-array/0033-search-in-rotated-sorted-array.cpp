class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n=nums.size();
        int l=0,r=n-1,m;
        while(l<=r){
            m=(l+r)/2;
            cout<<nums[m]<<" ";
            if(nums[m]==t)return m;
            if(nums[m]>nums[r]){
                if(t<=nums[r] || t>nums[m] )l=m+1;
                else r=m-1;
            }
            else{
                if(t>nums[m] && t<=nums[r])l=m+1;
                else r=m-1;
            }
        }
        return -1;
    }
};