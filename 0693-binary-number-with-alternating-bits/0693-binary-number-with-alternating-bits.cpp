class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n==1 ||n==0)return true;
        int t=n%2;
        n=n/2;
        while(n>0){
            if(n%2==t)return false;
            else{
                t=n%2;
            }
            n=n/2;
        }
        return true;
    }
};