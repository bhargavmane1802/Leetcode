class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>temp;
        for(int i:nums){
            temp[i]++;
        }
        if(k==1){
            int ans=-1;
            for(auto x:temp){
                if(x.second==1){
                    ans=max(ans,x.first);
                }
            }
            return ans;
        }
        if(k==nums.size()){
            int ans=-1;
            for(int i:nums)ans=max(ans,i);
            return ans;
        }
        int mx=max(nums[0],nums[nums.size()-1]);
        int mn=min(nums[0],nums[nums.size()-1]);
        if(temp[mx]==1)return mx;
        if(temp[mn]==1)return mn;
        return -1;
    }
};