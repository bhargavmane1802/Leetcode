class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int a=0;
        int b=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(target==nums[i])b++;
            else if(target>nums[i])a++;
        }
        vector<int>ans;
        for(int i=0;i<b;i++){
            ans.push_back(a);
            a++;
        }
        return ans;
    }
};