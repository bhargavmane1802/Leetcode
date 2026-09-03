class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int mn=0;
        int check=true;
        for(int i=0;i<n;i++){
            if(nums[i]<nums[mn]){
                mn=i;
            }
            if(nums[i]%2==1){
                check=false;
            }
        }
        if(check)return true;
        if(nums[mn]%2==0)return false;
        return true;
    }
};