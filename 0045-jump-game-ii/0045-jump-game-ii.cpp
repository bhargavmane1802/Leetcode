class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        for(int i=0;i<n;i++){
            nums[i]+=i;
        }
        int ans=0;
        int l=0;
        int r=0;
        while(true){
            int t=r;
            for(int i=l;i<=r;i++){
                t=max(nums[i],t);
                if(t>=n-1)return ans+1;
            }
            l=r+1;
            r=t;
            ans++;
        }
        return 0;
    }
};