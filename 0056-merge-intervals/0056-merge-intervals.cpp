class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        int n=in.size();
        int x=0;
        vector<vector<int>>ans;
        sort(in.begin(),in.end());
        ans.push_back(in[0]);
        for(int i=1;i<n;i++){
            if(ans[x][0]<=in[i][0] && ans[x][1]>=in[i][0]){
                ans[x][1]=max(in[i][1],ans[x][1]);
            }
            else {
                ans.push_back(in[i]);
                x++;
            }
        }
        return ans;
    }
};