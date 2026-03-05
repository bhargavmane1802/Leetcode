class Solution {
public:
    int minOperations(string s) {
        bool temp;
        int ans=0;
        int n=s.size();
        if(s[0]=='0')temp=true;
        else temp=false;
        for(char i:s){
        if(temp && i=='1')ans++;
        if(!temp && i=='0')ans++;
        temp=!temp;
        }
        return min(ans,n-ans);
    }
};