class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=0;
        for(int k:piles)mx=max(mx,k);
        int i;
        int l=1;
        int r=mx;
        while(l<=r){
            int mid=l+(r-l)/2;
            int sum=0;
            for(int j:piles ){
                int m=j/mid;
                int rem=j%mid;
                if(rem!=0)m++;
                sum+=m;
                if(sum>h)break;
            }
            if(sum<=h)r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};