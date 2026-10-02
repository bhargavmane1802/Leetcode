class Solution {
public:
    void find(vector<string>& ans ,int o,int c, string temp,int n){
        if(temp.size()>=n){
            ans.push_back(temp);
        }
        if(o!=0){
            find(ans,o-1,c,temp+'(',n);
        }
        if(c!=0 && o<c){
            find(ans,o,c-1,temp+')',n);
        }
        return;

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans ;
        find(ans,n,n,"",2*n);
        return ans;
    }
};