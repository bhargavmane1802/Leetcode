class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>lower(26);
        vector<int>upper(26);
        int ans=0;
        for(char i:word){
            if(i>='a' && i<='z'){
                lower[i-97]++;
            }
            else upper[i-65]++;
        }
        for(int i=0;i<26;i++){
            if(0==upper[i] || lower[i]==0)continue;
            ans++;
        }
        return ans;
    }
};