class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        bool flag=true;
        for(int i=1;i<n;i++){
            if(flag){
                if(nums[i]<nums[i-1]){
                    flag=false;
                    if(nums[i]>nums[0])return false;
                }
            }
            else{
                if(nums[i]<nums[i-1])return false;
                if(nums[i]>nums[0])return false;
            }
        }
        return true;
        
    }
};