class Solution {
public:
    bool solve( vector<int>&nums,int k,int mid){
        int p=1;
        int s=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+s>mid){
                p++;
                s=nums[i];
            }
            else{
                s+=nums[i];
            }
        }
        return (p<=k);
    }

    int splitArray(vector<int>& nums, int k) {
        int l=nums[0];
        int r=0;
        for(int i:nums){
            l=max(l,i);
            r+=i;
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(nums,k,mid)){
                r=mid-1;
            }
            else l=mid+1;
        }
        return l;

        
    }
};