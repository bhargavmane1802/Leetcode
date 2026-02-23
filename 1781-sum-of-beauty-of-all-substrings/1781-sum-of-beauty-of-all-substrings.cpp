class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int>freq;
            char mx=s[i];
            char mn=s[i];
            for(int j=i;j<s.size();j++){
                freq[s[j]]++;
                if(freq[mx]<freq[s[j]])mx=s[j];
                for(auto x:freq){
                    if(freq[mn]>x.second){
                        mn=x.first;
                    }
                }
                ans+=(freq[mx]-freq[mn]);
            }
        }
        return ans;
    }
};