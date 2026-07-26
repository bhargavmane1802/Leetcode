class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mxp=nums[0]*nums[1]*nums[2];
        int mnp=mxp;
        int n=nums.size();
        // int ans=0;
        // for(int i=3;i<n;i++){
        //     mxp=max()
        //     ans=max(ans,max(mxp,mnp));
        // }
        sort(nums.begin(),nums.end());
        int ans=max((nums[0]*nums[1]*nums[n-1]),(nums[n-1]*nums[n-2]*nums[n-3]));
        return ans;
    }
};