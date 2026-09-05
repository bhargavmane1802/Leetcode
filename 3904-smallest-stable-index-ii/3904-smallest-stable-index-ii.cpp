class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n=nums.size();
        vector<int>mn(n);
        vector<int>mx(n);
        int m=nums[0];
        for(int i=0;i<n;i++){
            m=max(nums[i],m);
            mx[i]=m;
        }
        m=nums[n-1];
        for(int i=n-1;i>=0;i--){
            m=min(nums[i],m);
            mn[i]=m;
        }
        for(int i=0;i<n;i++){
            if(mx[i]-mn[i]<=k)return i;
        }
        return -1;
    }
};