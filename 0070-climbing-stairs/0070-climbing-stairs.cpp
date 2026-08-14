class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        int x=2;
        int y=1;
        for(int i=2;i<n;i++){
            int t=x;
            x+=y;
            y=t;
        }
        return x;
    }
};