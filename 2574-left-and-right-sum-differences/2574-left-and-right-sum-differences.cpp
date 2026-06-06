class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n);
        vector<int>right(n);
        int s=0;
        for(int i=1;i<n;i++){
            s+=nums[i-1];
            left[i]=s;
        }
        s=0;
        for(int i=n-2;i>=0;i--){
            s+=nums[i+1];
            right[i]=s;
        }
        for(int i=0;i<n;i++){
            nums[i]=abs(left[i]-right[i]);
        }
        return nums;
    }
};