class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>temp;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')temp.push(i);
            else if(s[i]==')'){
                reverse(s.begin()+temp.top(),s.begin()+i);
                temp.pop();
            }
        }
        cout<<s;
        string ans="";
        for(char c:s){
            if(c!=')' && c!='(')ans.push_back(c);
        }
        return ans;
    }
};