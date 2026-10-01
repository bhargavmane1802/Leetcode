class Solution {
public:
bool solve(int i,string &s, vector<string>& word,unordered_set<int>&mp,vector<int>&dp){
    if(i>=s.size())return true;
    int n=s.size()-i;
    if(mp.find(i)!=mp.end())return false;
    if(dp[i]==1)return true;
    else if(dp[i]==0)return false;
    for(string c:word){
        int x=c.size();
        if(n<x)continue;
        string temp=s.substr(i,x);
        if(temp==c){
            if(solve(i+x,s,word,mp,dp)){
                dp[i]=1;
            return true;}
            mp.insert(i+x);
        }
    }
    dp[i]=0;
    return false;
}
    bool wordBreak(string s, vector<string>& word) {
        unordered_set<int>temp;
        int n=s.size();
        vector<int>dp(n,-1);
        return solve(0,s,word,temp,dp);
    }
};