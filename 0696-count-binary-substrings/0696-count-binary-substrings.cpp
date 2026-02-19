class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.size()==1)return 0;
        int ans=0;
        int n=s.size();
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                int a=i-1;
                int b=i;
                while(a>=0 && b<n && s[a]==s[i-1] && s[b]==s[i]){
                    ans++;
                    a--;b++;
                }
            }
        }
        return ans;
    }
};