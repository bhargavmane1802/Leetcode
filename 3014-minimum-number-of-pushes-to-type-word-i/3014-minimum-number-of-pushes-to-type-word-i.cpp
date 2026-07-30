class Solution {
public:
    int minimumPushes(string word) {
        vector<int>temp(26);
        for(char c:word){
            temp[c-'a']++;
        }
        sort(temp.rbegin(),temp.rend());
        int ans=0;
        for(int i=0;i<26;i++){
            int x=1+(i/8);
            ans+=(temp[i]*x);
        }
        return ans;
    }
};