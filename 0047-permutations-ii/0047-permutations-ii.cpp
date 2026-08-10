
class Solution {
public:
    void solve(int idx,vector<int>&nums,vector<vector<int>>&ans){
        if(idx>=nums.size()){
            ans.push_back(nums);
            return ;
        }
        unordered_set<int>temp;
        for(int i=idx;i<nums.size();i++){
            if(temp.find(nums[i])==temp.end()){
                swap(nums[i],nums[idx]);
                solve(idx+1,nums,ans);
                swap(nums[i],nums[idx]);
            }
            temp.insert(nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(0,nums,ans);
        return ans;
        
    }
};