class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<long long ,long long>mp;
        long long ans=0;
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i])%k;
            int a=sum;
            if(a<0){
                a=k+a;
            }
            ans+=mp[a];
            mp[a]++;
        }
        return ans+mp[0];
    }
};
