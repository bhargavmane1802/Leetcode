class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int a=-1;
        int b=-1;
        int p=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j] && nums[i]+nums[j] == target&& nums[i]*nums[j] >p){
                    a=i;
                    b=j;
                    p=nums[i]*nums[j];
                }
                else if(nums[i]<nums[j] && nums[i]+nums[j] == target&& nums[i]*nums[j] >p){
                    a=j;
                    b=i;
                    p=nums[i]*nums[j];
                }
            }
        }
        return {a,b};
        
    }
};