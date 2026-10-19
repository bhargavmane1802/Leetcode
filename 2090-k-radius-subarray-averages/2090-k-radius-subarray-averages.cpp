class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        if(k==0)return nums;
        for(int i=0;i<(2*k) & i<n;i++){
            sum+=nums[i];
        }
        vector<int>ans(n,-1);
        for(int i=k;i<n-k;i++){
            sum+=nums[i+k];
            ans[i]=(sum/((2*k)+1));
            sum-=nums[i-k];
        }
        return ans;
    }
};