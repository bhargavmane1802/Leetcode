class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans=0;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            ans+=mp[s[i]];
            int j=i-1;
            while(j>=0 && mp[s[j]]<mp[s[i]]){
                ans-=mp[s[j]];
                j--;
            }
            i=j+1;
        }
        return ans;
    }
};