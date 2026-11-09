class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans=0;
        int m=0,n=p.size();
        for(int i=0;i<n;i++){
            if(p[m]>p[i])m=i;
            ans=max(p[i]-p[m],ans);
        }
        return ans;

    }
};