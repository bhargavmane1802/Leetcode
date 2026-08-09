class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>q;
        for(char c:s){
            if(q.empty()){
                q.push(c);
                continue;
            }
            if(c==')' && q.top()=='('){
                q.pop();
            }
            else{
                q.push(c);
            }
        }
        return q.size();
    }
};