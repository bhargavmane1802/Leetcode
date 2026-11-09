class Solution {
public:
    int coinChange(vector<int>& coins, int a) {
        vector<int>nums(a+1,INT_MAX-1);
        nums[0]=0;
        for(int i:coins){
            if(i>a)continue;
            for(int j=i;j<=a;j++){
                nums[j]=min(nums[j-i]+1,nums[j]);
            }
        }
        if(nums.back()==INT_MAX-1)return -1;
        return nums.back();

    }
};