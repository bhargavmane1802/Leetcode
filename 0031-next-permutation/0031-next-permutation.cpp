class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
        while(i>0){
            if(nums[i]>nums[i-1]){
                break;
            }
            i--;
        }
        if(i==0){
            reverse(nums.begin(),nums.end());
        }
        else {
            int x=n-1;
            while(nums[x]<=nums[i-1])x--;
            swap(nums[i-1],nums[x]);
            reverse(nums.begin()+i,nums.end());
        }
        
    }
};