class Solution {
public:
    string largestOddNumber(string s) {
        int n=s.size();
        int x=-1;
        for(int i=n-1;i>=0;i--){
            int a=s[i]-'0';
            if(a%2==1){
                x=i;
                break;
            }
        }
        if(x==-1)return "";
        return s.substr(0,x+1);
    }
};