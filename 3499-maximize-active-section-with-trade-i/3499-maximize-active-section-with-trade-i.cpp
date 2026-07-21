class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int c=0;
        int n=s.size();
        vector<int>left(n);
        vector<int>right(n);
        for(int i=0;i<n;i++){
            if(s[i]=='0')c++;
            else {
                if(i!=n-1 && s[i+1]=='1'){
                    left[i]=c;
                    continue;
                }
                left[i]=c;
                c=0;
            }
        }
        c=0;
        
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')c++;
            else {
                ans++;
                if(i!=0 && s[i-1]=='1'){
                    right[i]=c;
                    continue;
                }
                right[i]=c;
                c=0;
            }
        }
        int m=0;
        for(int i=0;i<n;i++){
            if(left[i]!=0 && right[i]!=0){
                m=max(m,left[i]+right[i]);
            }
        }
        return ans+m;

        
    }
};