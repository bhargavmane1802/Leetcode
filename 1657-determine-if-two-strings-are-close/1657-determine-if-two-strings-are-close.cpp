class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        if(n!=m)return false;
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        set<char>s1;
        set<char>s2;
        vector<int>a1;
        vector<int>a2;
        for(char c:word1){
            m1[c]++;
            s1.insert(c);
        }
        for(char c:word2){
            s2.insert(c);
            m2[c]++;
        }
        for(auto x:m1){
            a1.push_back(x.second);
        }
        for(auto x:m2){
            a2.push_back(x.second);
        }
        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());
        return (a1==a2 && s1==s2);
    }
};