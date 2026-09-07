class Solution {
public:
bool solve(int i,string &s, vector<string>& word,unordered_set<int>&mp){
    if(i>=s.size())return true;
    int n=s.size()-i;
    if(mp.find(i)!=mp.end())return false;
    for(string c:word){
        int x=c.size();
        if(n<x)continue;
        string temp=s.substr(i,x);
        if(temp==c){
            if(solve(i+x,s,word,mp))
            return true;
            mp.insert(i+x);
        }
    }
    return false;
}
    bool wordBreak(string s, vector<string>& word) {
        unordered_set<int>temp;
        return solve(0,s,word,temp);
    }
};