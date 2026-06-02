class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n=ls.size();
        int m=ws.size();
        int l=0,w=0;
        for(int i=0;i<n;i++){
            if(ls[i]+ld[i]<ls[l]+ld[l]){
                l=i;
            }
        }
        for(int i=0;i<m;i++){
            if(ws[i]+wd[i]<ws[w]+wd[w]){
                w=i;
            }
        }
        l=ls[l]+ld[l];
        w=ws[w]+wd[w];
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,max(w,ls[i])+ld[i]);
        }
        for(int i=0;i<m;i++){
            ans=min(ans,max(l,ws[i])+wd[i]);
        }
        return ans;
    }
};