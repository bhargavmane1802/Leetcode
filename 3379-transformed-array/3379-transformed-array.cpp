class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            int s=0;
            if(nums[i]>0){
                s=nums[i]+i;
                s=s%n;
                temp[i]=nums[s];
            }
            else if (nums[i]<0){
                if(i>=abs(nums[i])){
                    temp[i]=nums[i-abs(nums[i])];
                }
                else{
                    temp[i]=nums[n-abs(nums[i])+i];
                }
            }
            else{
                temp[i]=nums[i];
            }

        }
        return temp;
    }
};