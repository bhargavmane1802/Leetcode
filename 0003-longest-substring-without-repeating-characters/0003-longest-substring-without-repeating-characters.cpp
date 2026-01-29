class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int ans=0;
        unordered_set<char>temp;
        while(r<s.size()){
            if(temp.find(s[r])==temp.end()){
                temp.insert(s[r]);
                ans=max(ans,r-l+1);
                r++;
            }
            else{
                while(temp.find(s[l])!=temp.end()){
                    temp.erase(s[l]);
                    l++;
                }
            }
        }
        return ans;
    }
};