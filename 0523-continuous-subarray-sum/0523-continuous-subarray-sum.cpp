class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<long long>mp;
        int n=nums.size();
        long long sum=0;
        int prev=-1;
        for(int i=0;i<n;i++){
            sum=(sum+nums[i])%k;
            if(i!=0 && sum==0)return true;
            if(mp.find(sum)==mp.end()){
                mp.insert(prev);
                prev=sum;
            }
            else return true;
        }
        return false;
    }
};