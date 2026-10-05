class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        vector<int>temp(n);
        stack<int>stk;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                stk.push(i);
            }
            else {
                int t=stk.top();
                stk.pop();
                if (s[t+1]=='(') {
                    temp[i]=2*temp[i-1];
                }
                else temp[i]+=1;
                if(t==0)continue;
                if (s[t-1]==')'){
                    temp[i]+=temp[t-1];
                }
            }
        }
        return temp.back();
    }
};