class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>ca(n,0);
        vector<int>cb(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b')c++;
            cb[i]=c;
        }
        c=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a')c++;
            ca[i]=c;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,(ca[i]+cb[i]));
        }
        return ans-1;

    }
};