class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==i+1){
                i++;
            }
            else{
                int x=nums[i];
                if(nums[x-1]==x)return x;
                swap(nums[i],nums[x-1]);
            }
        }
        return-1;
    }
};