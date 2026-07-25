class Solution {
public:
    bool solve(int m,vector<int>&p,int h){
        int x=0;
        for(int i=0;i<p.size();i++){
            int a=p[i]/m;
            if(p[i]%m!=0)a++;
            x+=a;
            if(x>h)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int tsum=piles[0];
        for(int i:piles){
            tsum=max(tsum,i);
        }
        int l=1;
        int r=tsum;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(mid,piles,h)){
                r=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};