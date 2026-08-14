class Solution {
public:
    bool isValid(string s) {
        stack<char>temp;
        unordered_map<char,char>mp;
        mp[')']='(';
        mp[']']='[';
        mp['}']='{';
        for(char i:s){
            if(i=='}' || i==']' || i==')'){
                if(temp.empty() || mp[i]!=temp.top())return false;
                temp.pop();
            }
            else temp.push(i);
        }
        if(!temp.empty())return false;
        return true;
    }
};