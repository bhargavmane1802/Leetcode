class Solution {
public:
    void solve (vector<vector<int>>& ans,vector<int>& temp,int idx,vector<int>&nums){
        if(idx>=int(nums.size())){
            ans.push_back(temp);
            return ;
        }
        solve(ans,temp,idx+1,nums);
        temp.push_back(nums[idx]);
        solve(ans,temp ,idx+1,nums);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,0,nums);
        return ans;
    }
};