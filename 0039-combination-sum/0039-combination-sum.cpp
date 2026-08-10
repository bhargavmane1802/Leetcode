class Solution {
public:
    void solve (vector<int>&c,int t,vector<vector<int>>&ans,int i,vector<int>temp,int sum){
        if(i>=c.size() || sum>t)return ;
        if(sum==t){
            ans.push_back(temp);
            return ;
        }
        solve(c,t,ans,i+1,temp,sum);
        temp.push_back(c[i]);
        sum+=c[i];
        solve(c,t,ans,i,temp,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>>ans;
        solve(c,t,ans,0,{},0);
        return ans;
    }
};