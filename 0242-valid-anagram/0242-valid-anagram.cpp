class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>a(26);
        vector<int>b(26);
        int n=s.size();
        int m=t.size();
        if(n!=m)return false;
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
            b[t[i]-'a']++;
        }
        return a==b;
    }
};