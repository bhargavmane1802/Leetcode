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
        ans=min(min(max(x,y)+1,n-min(x,y)),n-max(x,y)+min(x,y)+1);
        return ans;

    }
};