class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp;
        unordered_set<string>temp;
        vector<string>v;
        int x=0;
        for(int i=0;i<=s.size();i++){
            if(s[i]==' ' ||i==s.size()){
                string t=s.substr(x,i-x);
                x=i+1;
                v.push_back(t);
            }
        }
        if(pattern.size()!=v.size())return false;
        int i=0;
        for(auto p:pattern){
            if(mp[p]==""){
                if(temp.find(v[i])!=temp.end())return false;
                mp[p]=v[i];
            }
            else{
                if(mp[p]!=v[i])return false;
            }
            temp.insert(v[i]);
            i++;
        }
        return true;
    }
};