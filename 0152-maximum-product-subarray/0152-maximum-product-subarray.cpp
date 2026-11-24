class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size(),posi=1,nege=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                posi*=nums[i];
                nege*=nums[i];
                ans=max(posi,ans);
            }
            else if(nums[i]<0){
                if(nege>0){
                    posi=1;
                    nege*=nums[i];
                    continue;
                }
                swap(posi,nege);
                posi*=nums[i];
                nege*=nums[i];
                ans=max(ans,posi);
            }
            else {
                posi=1;
                nege=1;
                ans=max(ans,0);
            }
        }
        // for(int i=0;i<n;i++){
        //     t*=nums[i];
        //     ans=max(t,ans);
        //     if(t==0)t=1;
        // }
        // t=1;
        // for(int i=n-1;i>=0;i--){
        //     t*=nums[i];
        //     ans=max(t,ans);
        //     if(t==0)t=1;
        // }
        return ans;
    }
};