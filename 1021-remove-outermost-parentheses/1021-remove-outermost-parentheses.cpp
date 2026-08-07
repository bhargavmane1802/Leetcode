class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<int>nums;
        stack<char>temp;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(temp.empty())nums.push_back(i);
            if(s[i]=='(')temp.push('(');
            else temp.pop();
            if(temp.empty())nums.push_back(i);
        }
        int del=0;
        for(int i:nums){
            s.erase(i-del,1);
            del++;
        }
        return s;
        
    }
};