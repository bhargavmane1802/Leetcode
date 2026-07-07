class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        long long x=n;
        long long sum=0;
        long long i=0;
        while(x>0){
            int digit=x%10;
            x/=10;
            if(digit!=0){
                sum+=digit;
            ans+=(pow(10,i)*digit);
            i++;
            }
        }
        return ans*sum;
    }
};