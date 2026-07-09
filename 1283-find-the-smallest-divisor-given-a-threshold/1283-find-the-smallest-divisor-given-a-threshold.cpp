class Solution {
public:
    int smallestDivisor(vector<int>& nums, int target) {
        int tsum=0;
        for(int i:nums)tsum=max(tsum,i);
        int l=1;
        int r=tsum;
        while(l<=r){
            int mid=l+(r-l)/2;
            int sum=0;
            for(int i:nums){
                int x=i/mid;
                if(i%mid>0)x++;
                sum+=x;
            }
            if(sum>target){
               l=mid+1;
            }
            else r=mid-1;
        }
        return l;
    }
};