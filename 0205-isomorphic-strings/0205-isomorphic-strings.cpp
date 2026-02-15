class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())return false;
        unordered_map<char,vector<int>>freq;
        unordered_set<char>temp;
        for(int i=0;i<s.size();i++){
            freq[s[i]].push_back(i);
            temp.insert(s[i]);
        }
        for(auto i:temp){
            char x=t[freq[i][0]];
            for(int j:freq[i]){
                if(t[j]!=x)return false;
            }
        }
        return true;
        
    }
};