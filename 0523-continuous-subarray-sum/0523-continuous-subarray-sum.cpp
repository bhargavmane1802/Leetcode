class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long ,long long>mp;
        mp[0]=-1;
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i])%k;
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
            else if(i-mp[sum]>1)return true;
        }
        return false;
    }
};