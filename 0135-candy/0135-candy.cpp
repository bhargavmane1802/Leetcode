class Solution {
public:
    int candy(vector<int>& rate) {
        int n=rate.size();
        vector<pair<int,int>>nums(n);
        for(int i=0;i<n;i++){
            nums[i]={rate[i],i};
        }
        sort(nums.begin(),nums.end());
        vector<int>val(n,1);
        for(auto x:nums){
            int idx=x.second;
            if(idx>0 && rate[idx-1]>rate[idx] && val[idx-1]<=val[idx]){
                val[idx-1]=val[idx]+1;
            }
            if(idx<n-1 && rate[idx+1]>rate[idx] && val[idx+1]<=val[idx]){
                val[idx+1]=val[idx]+1;
            }

        }
        int ans=0;
        for(int i:val){ans+=i;}
        return ans;

    }
};