class Solution {
public:
    void solve(int k,vector<int>&nums,vector<vector<int>>&ans){
        if(k>=nums.size()){
            ans.push_back(nums);
            return ;
        }
        solve(k+1,nums,ans);
        for(int i=k;i<nums.size();i++){
            if(nums[i]!=nums[k]){
                swap(nums[i],nums[k]);
                solve(k+1,nums,ans);
                swap(nums[i],nums[k]);
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0,nums,ans);
        return ans;
        
    }
};