class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        ans.push_back(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i][0]<=ans.back()[1]){
                ans.back()[1]=max(ans.back()[1],nums[i][1]);
            }else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};