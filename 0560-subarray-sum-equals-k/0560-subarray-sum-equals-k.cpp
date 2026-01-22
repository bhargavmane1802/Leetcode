class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_set<int>mp;
        int ans=0;
        int sum=0;
        for(int i:nums){
            sum+=i;
            if(sum==k)ans++;
            else if (mp.find(sum-k)!=mp.end())ans++;
            mp.insert(sum);
        }
        return ans;
    }
};