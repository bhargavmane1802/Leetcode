class Solution {
public:
    bool canJump(vector<int>& nums) {
        int x=0;
        int n=nums.size();
        if(nums.size()==1)return true;
        for(int i=0;i<n;i++){
            nums[i]+=i;
        }
        
        for(int i=0;i<n && x>=i;i++){
            x=max(x,nums[i]);
            if(x>=n-1)return true;
        }
        return false;
    }
};