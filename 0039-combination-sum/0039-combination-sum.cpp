class Solution {
public:
    void solve(vector<int>&candy,int sum,int idx,vector<int>&temp,vector<vector<int>>&ans,int t){
        if(idx >=candy.size()){
            if(sum==t)ans.push_back(temp);
            return;
        }
        solve(candy,sum,idx+1,temp,ans,t);
        sum+=candy[idx];
        if(sum>t)return;
        temp.push_back(candy[idx]);
        solve(candy,sum,idx,temp,ans,t);
        temp.pop_back();
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int sum=0,idx=0;
        vector<int>temp;
        solve(candidates,sum,idx,temp,ans,target);
        return ans;
    }
};