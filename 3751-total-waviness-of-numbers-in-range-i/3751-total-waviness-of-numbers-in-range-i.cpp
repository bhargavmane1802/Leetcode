class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int n,a,b,c=-1;
        int ans=0;
        for(int i=num1;i<=num2;i++){
            n=i;
            if(n<100)continue;
            a=n%10;
            n/=10;
            b=n%10;
            n/=10;
            while(n>0){
                if(c!=-1){
                    swap(a,c);
                    swap(b,a);
                }
                c=n%10;
                n/=10;
                if((b>a && b>c)|| (b<a && b<c))ans++;
            }
            c=-1;
        }
        return ans;
    }
};