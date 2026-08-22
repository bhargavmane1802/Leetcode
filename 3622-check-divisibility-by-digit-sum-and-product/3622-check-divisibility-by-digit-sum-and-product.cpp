class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0;
        long long p=1;
        int x=n;
        while(x>0){
            int a =x%10;
            sum+=a;
            p*=a;
            x/=10;
        }
        // cout<<sum<<" "<<p;
        long long check=sum+p;
        if(n%check==0)return true;
        return false;
    }
};