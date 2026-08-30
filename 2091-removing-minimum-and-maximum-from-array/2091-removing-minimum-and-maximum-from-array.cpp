class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int x=0;
        int y=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>nums[x])x=i;
            if(nums[i]<nums[y])y=i;
        }
        int ans;
        int m=min(x,y);
        int mx=max(x,y);
        ans=min(min(mx+1,n-m),n-mx+m+1);
        return ans;

    }
};