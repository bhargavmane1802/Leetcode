class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n=ls.size();
        int m=ws.size();
        int ans=INT_MAX;
        int l,w;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                l=ls[i]+ld[i];
                if(l>=ws[j]) l+=wd[j];
                else l+=(ws[j]-l)+wd[j];
                w=ws[j]+wd[j];
                if(w>=ls[i]) w+=ld[i];
                else w+=(ls[i]-w)+ld[i];
                ans=min(ans,min(l,w));
            }
        }
        return ans;
    }
};