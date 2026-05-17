class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        sort(in.begin(),in.end(),[](auto a,auto b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });
        vector<vector<int>>ans;
        int t=0;
        ans.push_back(in[0]);
        int i=1;
        int n=in.size();
        int j=0;
        while(i<n){
            if(ans[t][1]>=in[i][0]){
                ans[t][1]=max(ans[t][1],in[i][1]);
                i++;
            }
            else{
                ans.push_back(in[i]);
                t++;
                i++;
            }
        }
        return ans;
    }
};