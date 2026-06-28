class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums[0]=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>1){
                nums[i]=nums[i-1]+1;
            }
        }
        return nums[n-1];
    }
};