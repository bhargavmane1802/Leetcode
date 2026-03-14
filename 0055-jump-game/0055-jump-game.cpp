class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
         if(n==1)return true;
        int m=0;
        for(int i=0;i<n;i++){
            if(i<=m){
                m=max(m,i+nums[i]);
            }
           if(m>=n-1)return true;
        }
        return false;
    }
};