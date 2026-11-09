class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(300);
        int l=0,r=0;
        int ans=0;
        for(char c:s){
            r++;
            int t='z'-c;
            t+=20;
            freq[t]++;
            while(freq[t]>1){
                freq['z'-s[l]+20]--;
                l++;
            }
            ans=max(ans,(r-l));
        }
        return ans;
    }
};