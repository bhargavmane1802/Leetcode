class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(int i:nums)sum+=i;
        int n=nums.size();
        int t=sum-x;
        if(t<0)return -1;
        if(t==x)return n;
        int ans=INT_MAX;
        sum=0;
        int j=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>t){
                sum-=nums[j];
                j++;
            }
            if(sum==t){
                ans=min(n-(i-j+1),ans);
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;


    }
};