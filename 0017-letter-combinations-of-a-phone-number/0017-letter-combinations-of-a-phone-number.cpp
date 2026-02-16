class Solution {
public:
    void solve(vector<string>&check,vector<string>& ans,string& s,int x,string curr){
        if(x>=s.size()){
            ans.push_back(curr);
            return;
        }
        int t=s[x]-'0';
        t-=2;
        for(int i=0;i<check[t].size();i++){
            solve(check,ans,s,x+1,curr+check[t][i]);
        }
    }
    vector<string> letterCombinations(string s) {
        vector<string>check={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string curr="";
        solve(check,ans,s,0,curr);
        return ans;
        
    }
};