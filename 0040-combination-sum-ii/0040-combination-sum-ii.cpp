class Solution {
public:
    void solve(vector<int>& c, int t,int sum,int idx,vector<int>temp,vector<vector<int>>&ans){
        if(sum==t){
            ans.push_back(temp);
            return ;
        }
        if(idx>=c.size() || sum>t)return ;
        temp.push_back(c[idx]);
        sum+=c[idx];
        solve(c,t,sum,idx+1,temp,ans);
        sum-=c[idx];
        temp.pop_back();
        for(int i=idx+1 ;i<c.size();i++){
            if(c[i]==c[i-1])continue;
            if(sum+c[i]>t)return;
            temp.push_back(c[i]);
            sum+=c[i];
            solve(c,t,sum,i+1,temp,ans);
            sum-=c[i];
            temp.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>>ans;
     sort(c.begin(),c.end());
     solve(c,t,0,0,{},ans);
     return ans;   
    }
};