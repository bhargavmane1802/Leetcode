class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char>one;
        for(char i:s){
            if(i=='#' && one.size()>0)one.pop_back();
            else if(i!='#')one.push_back(i);
        }
        vector<char>two;
        for(char i:t){
            if(i=='#' && two.size()>0)two.pop_back();
            else if(i!='#')two.push_back(i);
        }
        return one ==two;
    }
};