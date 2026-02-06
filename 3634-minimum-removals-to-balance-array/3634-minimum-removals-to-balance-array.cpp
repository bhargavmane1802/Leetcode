class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int ans=1;
        while(j<nums.size()){
            while(j<nums.size() && nums[j]<=nums[i]*k){
                j++;
            }
            ans=max(ans,j-i);
            i++;

        }
        return nums.size()-ans;
    }
};