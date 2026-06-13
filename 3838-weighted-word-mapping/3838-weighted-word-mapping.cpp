class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto x:words){
            int sum=0;
            for(auto i:x){
                sum+=weights[(i-'a')];
            }
            sum=(sum%26);
            cout<<sum<<" ";
            sum=abs(sum-26);
            ans+=char('a'+sum-1);
        }
        return ans;
    }
};