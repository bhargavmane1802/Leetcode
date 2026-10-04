class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end(),[](auto & a,auto &b){
            if(a[1]==b[1])return a[0]>b[0];
            return a[1]<b[1];
        });
        int ans=0;
        int l=inter[0][0];
        int r=inter[0][1];
        int n=inter.size();
        for(int i=1;i<n;i++){
            if(r>inter[i][0]){
                ans++;
            }
            else {
                l=inter[i][0];
                r=inter[i][1];
            }
        }
        return ans;
    }
};