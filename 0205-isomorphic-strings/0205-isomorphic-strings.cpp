class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp;
        unordered_set<char>us;
        int n=s.size();
        int m=s.size();
        if(n!=m)return false;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                if(us.find(t[i])!=us.end()){
                    return false;
                }
                mp[s[i]]=t[i];
                us.insert(t[i]);
            }
            if(mp[s[i]]!=t[i])return false;
        }
        return true;
    }
};