class Solution {
public:
    bool solve(long long mid,vector<int>&b,int m,int k){
        for(int i=0;i<=b.size()-k;i++){
            if(m==0)break;
            for(int j=i;j<i+k;j++){
                if(b[j]>mid){
                    i=j;
                    break;
                }
                else{
                    if(j==(i+k-1)){
                        m--;
                        i=i+k-1;
                        break;
                    }
                }
            }
        }
        if(m==0)return true;
        return false;

    }

    int minDays(vector<int>& b, int m, int k) {
        long long n=b.size();
        if(n<(1ll*m*k))return -1;
        long long l=1;
        long long r=b[0];
        for(long long i:b){
            r=max(r,i);
        }
        while(l<=r){
            long long mid=l+(r-l)/2;
            cout<<mid<<" ";
            if(solve(mid,b,m,k)){
                r=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};