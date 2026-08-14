class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& c, int t,int sum,int idx,vector<int>temp){
        if(sum==t){
            ans.push_back(temp);
            return ;
        }
        if(idx>=c.size() || sum>t)return ;
        temp.push_back(c[idx]);
        sum+=c[idx];
        solve(c,t,sum,idx+1,temp);
        sum-=c[idx];
        temp.pop_back();
        for(int i=idx+1 ;i<c.size();i++){
            if(c[i]==c[i-1])continue;
            temp.push_back(c[i]);
            sum+=c[i];
            solve(c,t,sum,i+1,temp);
            sum-=c[i];
            temp.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
     sort(c.begin(),c.end());
     solve(c,t,0,0,{});
     return ans;   
    }
};