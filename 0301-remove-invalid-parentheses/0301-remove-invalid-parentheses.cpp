class Solution {
public:
unordered_set<string>check;
    void solve(string &s , string &temp,int idx,int a,int c,vector<string>&ans,int v){
        if(idx>=int (s.size())){
            if(c==0 && a==0 && check.find(temp)==check.end()){
                check.insert(temp);
                ans.push_back(temp);
            }
            return ;
        }
        if(s[idx]=='('){
            if(c>0){
                solve(s,temp,idx+1,a,c-1,ans,v);
                temp.push_back(s[idx]);
                solve(s,temp,idx+1,a,c,ans,v+1);
                temp.pop_back();
            }
            else{
                temp.push_back(s[idx]);
                solve(s,temp,idx+1,a,c,ans,v+1);
                temp.pop_back();
            }
        }
        else if (s[idx]==')'){
            if(a>0){
                solve(s,temp,idx+1,a-1,c,ans,v);
                if(v-1>=0){temp.push_back(s[idx]);
                solve(s,temp,idx+1,a,c,ans,v-1);
                temp.pop_back();}
            }
            else{
                if(v-1>=0){temp.push_back(s[idx]);
                solve(s,temp,idx+1,a,c,ans,v-1);
                temp.pop_back();}
            }
        }
        else{
            temp.push_back(s[idx]);
            solve(s,temp,idx+1,a,c,ans,v);
            temp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int a=0;
        int n=s.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')c++;
            else if(s[i]==')'){
                c--;
                if(c<0){
                    a++;
                    c=0;
                }
            }
        }
        vector<string>ans;
        string temp="";
        solve(s,temp,0,a,c,ans,0);
        return ans;
    }
};