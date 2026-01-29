class Solution {
public:
    int reverseBits(int n) {
        int ans=0;
        int x=31;
        while(n>0){
            if(n%2==1)ans+=pow(2,x);
            x--;
            n/=2;
        }
        return ans;
        
    }
};