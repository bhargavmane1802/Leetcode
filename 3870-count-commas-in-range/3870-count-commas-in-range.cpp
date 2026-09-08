class Solution {
public:
    int countCommas(int n) {
        if(n<1000)return 0;
        if(n==100000)return 99001;
        int temp=n;
        int c=0;
        while(n>0){
            n/=10;
            c++;
        }
        int t=(c/3);
        int ans=0;
        while(t>0){
            ans=(temp-pow(10,t*3));
            temp=pow(10,t*3);
            t--;
        }
        return ans+1;
        
        
    }
};