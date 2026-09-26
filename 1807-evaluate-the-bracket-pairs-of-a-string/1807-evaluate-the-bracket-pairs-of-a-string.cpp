class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        string ans="";
        unordered_map<string,string>mp;
        for(auto x:k){
            mp[x[0]]=x[1];
        }
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                i++;
                string temp="";
                while(s[i]!=')'){
                    temp.push_back(s[i]);
                    i++;
                }
                if(mp.find(temp)!=mp.end()){
                    temp=mp[temp];
                }
                else temp="?";
                ans+=temp;
            }
            else ans.push_back(s[i]);
        }
    return ans;
    }
};