class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        if(n==1)return ans;
        for(int i=1;i<n;i++){
            string s="";
            int c=0;
            for(int j=0;j<ans.size();j++){
                if(j==ans.size()-1 || ans[j]!=ans[j+1]){
                    s.push_back('0'+c+1);
                    s.push_back(ans[j]);
                    c=0;
                }
                else c++;
            }
            ans=s;
        }
        return ans;
    }
};