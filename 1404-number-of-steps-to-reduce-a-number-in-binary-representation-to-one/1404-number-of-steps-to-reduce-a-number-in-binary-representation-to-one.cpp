class Solution {
public:
    int numSteps(string s) {
        int n=s.size()-1;
        int ans=0;
        int c=0;
        while(n>0){
            if(s[n]=='0'){
                ans++;
                n--;
            }
            else{
                ans+=2;
                n--;
                while(n>=0 && s[n]=='1'){
                    ans++;
                    n--;
                }
                if(n>=0){s[n]='1';}
            }
        }
        return ans;
    }
};