class Solution {
public:
    int smallestNumber(int n, int t) {
        int x=n;
        while(true){
            int y=x;
            int p=1;
            while(y>0){
                p*=(y%10);
                y/=10;
                if(p==0)break;
            }
            if(p%t==0)return x;
            x++;
        }
        return 0;
    }
};