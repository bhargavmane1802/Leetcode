class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n=nums.size();
        if(1LL*m*k>n)return -1;
        int mx=0;
        for(int i :nums)mx=max(mx,i);
        int l=1;
        int r=mx;
        while(l<=r){
            int days=l+(r-l)/2;
            int x=0;
            int count=m;
            while(x<=n-k){
                bool check=true;
                for(int i=0;i<k;i++){
                    if(nums[i+x]>days){
                        check=false;
                        x+=i+1;
                        break;
                    }
                }
                if(check){
                    count--;
                    x+=k;
                    if(count==0)break;
                }
            }
            if(count==0)r=days-1;
            else l=days+1;
        }
        return l;
    }
};