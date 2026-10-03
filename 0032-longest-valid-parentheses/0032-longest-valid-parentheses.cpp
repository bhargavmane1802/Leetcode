class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(),l=0,r=0,c=0;
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            if(s[i]=='(')c++;
            else c--;
            if(s[i]=='(')l=i;
            else{
                if(c<0){
                    c=0;
                    dp[i]=-1;
                    l=i+1;
                }
                else {
                    int count =0;
                    while(l>=0){
                        if(l==0){
                        dp[i]=i-l+1;
                        c=0;
                        r=max(r,dp[i]);  
                        break;
                        }
                        if(s[l-1]=='('){
                            dp[i]=i-l+1;
                            l=l-1;
                            break;
                        }
                        else {
                            if(dp[l-1]==-1){
                                dp[i]=i-l+1;
                                c=0;
                                l=i+1;
                                break;
                            }
                            else{
                                count+=dp[l-1];
                                l-=dp[l-1];
                            }
                        }
                    }
                    if(l<0){
                        l=i+1;
                    }
                }
            } 
            r=max(r,dp[i]);  
        }
        // for(int i:dp)cout<<i<<" ";
        return r;
    }
};