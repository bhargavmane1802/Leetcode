class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0;
        int x=0;
        for(int i=0;i<g.size();i++){
            while(x<s.size() && g[i]>s[x])x++;
            if(x==s.size())return ans;
            ans++;
            x++;
        }
        return ans;
    }
};