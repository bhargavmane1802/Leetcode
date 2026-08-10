class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(128);
        int x=0;
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            freq[s[i]]++;
            while(freq[s[i]]==2){
                freq[s[x]]--;
                x++;
            }
            ans=max(ans,i-x+1);
        }
        return ans;
    }
};