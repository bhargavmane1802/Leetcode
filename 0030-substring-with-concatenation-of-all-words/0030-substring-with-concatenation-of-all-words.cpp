class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& word) {
        unordered_map<string,int>mp;
        vector<int>ans;
        for(string x:word){
            mp[x]++;
        }
        int l=word.size()*word[0].size();
        int k=word[0].size();
        int n=word.size();
        if(s.size()<l)return {};
        for(int i=0;i<=s.size()-l;i++){
            unordered_map<string,int>tp;
            for(int j=i;j<i+l;j+=k){
                string temp=s.substr(j,k);
                tp[temp]++;
            }
            if(tp==mp)ans.push_back(i);
        }
        return ans;
    }
};