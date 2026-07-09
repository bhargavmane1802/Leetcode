class Solution {
public:
    int shipWithinDays(vector<int>& nums, int days) {
        int tsum=0;
        int mn=nums[0];
        for(int i:nums){tsum+=i;mn=max(mn,i);}
        int l=mn;
        int r=tsum;
        int n=nums.size();
        while(l<=r){
            int mid=l+(r-l)/2;
            int d=0;
            int x=0;
            int csum=0;
            while(x<n){
                csum+=nums[x];
                if(csum>mid){
                    csum=nums[x];
                    d++;
                }
                x++;
            }
            d++;
            if(d>days){
                l=mid+1;
            }
            else r=mid-1;
        }
        return l;
    }
};