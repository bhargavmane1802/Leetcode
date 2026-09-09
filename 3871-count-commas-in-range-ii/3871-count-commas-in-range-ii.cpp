class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)return 0;
        long long temp=n;
        long long  c=0;
        while(n>0){
            n/=10;
            c++;
        }
        c--;
        long long t=(c/3);
        long long ans=0;
        while(t>0){
            ans+=((temp-pow(10,t*3))*t);
            ans++;
            temp=pow(10,t*3);
            t--;
        }
        return ans;
        
        
    }
};