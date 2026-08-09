class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>q(wordDict.begin(),wordDict.end());
       vector<int>temp;
       temp.push_back(0);
       int n=s.size();
       for(int i=0;i<n;i++){
        int a=temp.size();
        for(int j=0;j<a;j++){
            string t=s.substr(temp[j],i-temp[j]+1);
            if(q.find(t)!=q.end()){
                temp.push_back(i+1);
                break;
            }
        }
       }
       if(temp.back()==n)return true;
       return false;
    }
};