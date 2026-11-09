class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(300);
        int l=0,r=0;
        int ans=0;
        for(char c:s){
            r++;
            int t=c;
            freq[t]++;
            while(freq[t]>1){
                freq[s[l]]--;
                l++;
            }
            ans=max(ans,(r-l));
        }
        return ans;
    }
};