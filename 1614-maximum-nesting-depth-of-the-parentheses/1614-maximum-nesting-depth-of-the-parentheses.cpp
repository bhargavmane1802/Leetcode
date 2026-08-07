class Solution {
public:
    int maxDepth(string s) {
        stack<char>temp;
        int ans=0;
        for(char c:s){
            if(c=='(')
            temp.push('(');
            if(c==')')temp.pop();
            int a=temp.size();
            ans=max(ans,a);
        }
        return ans;
    }
};