class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(m!=n)return false;
        map<char,int>a;
        map<char,int>b;
        for(int i=0;i<n;i++){
            a[s[i]]++;
            b[t[i]]++;
        }
        return a==b;
    }
};