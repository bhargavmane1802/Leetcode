class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums.size();
        a/=2;
        int x=nums[a];
        int ans=0;
        for(int i:nums){
            ans+=(abs(i-x));
        }        
        return ans;
    }
};