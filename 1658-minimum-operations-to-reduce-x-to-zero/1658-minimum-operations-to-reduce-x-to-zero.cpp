class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<long long,long long>f;
        int n=nums.size();
        long long s=0;
        f[0]=-1;
        for(int i=0;i<n;i++){
            s+=nums[i];
            if(s>x)break;
            f[s]=i;
        }
        long long ans=INT_MAX;
        if(f.find(x)!=f.end())ans=f[x]+1;
        s=0;
        for(int i=n-1;i>=0;i--){
            s+=nums[i];
            if(s>x)break;
            if(f.find(x-s)!=f.end() && f[x-s] < i)ans=min(ans,f[x-s] + n-i+1);
        }
        if(ans==INT_MAX)return -1;
        return ans;
        
    }
};