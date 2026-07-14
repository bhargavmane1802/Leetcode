class Solution {
public:
    string removeStars(string s) {
        string ans="";
        for(char c:s){
            if(c=='*' && ans.size()>0){
                ans.pop_back();
            }
            else ans.push_back(c);
        }
        return ans;
    }
};