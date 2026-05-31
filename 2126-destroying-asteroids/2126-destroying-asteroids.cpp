class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long x=m;
        for(int i=0;i<n;i++){
            if(nums[i]>x)return false;
            x+=nums[i];
        }
        return true;
    }
};