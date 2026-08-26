class Solution {
public:
    int candy(vector<int>& r) {
        int n=r.size();
        if(n==1)return 1;
        vector<pair<int,int>>c(n);
        for(int i=0;i<n;i++){
            c[i]={r[i],i};
        }
        sort(c.begin(),c.end(),[](auto &a ,auto &b){
            if(a.first==b.first){
                return a.second<=b.second;
            }
            return a.first<b.first;
        });
        int ans=0;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            int a=c[i].second;
            if(a==0){
                if(r[a]>r[a+1]){
                      nums[a]=nums[a+1]+1;
                }
            }
            else if(a==n-1){
                if(r[a-1]<r[a]){
                    nums[a]=nums[a-1]+1;
                }
            }
            else {
                if(r[a-1]<r[a] && r[a+1]<r[a]){
                    nums[a]=max(nums[a-1],nums[a+1])+1;
                }
                else if(r[a-1]<r[a]){
                    nums[a]=nums[a-1]+1;
                }
                else if(r[a+1]<r[a]){
                    nums[a]=nums[a+1]+1;
                }
            }
            if(nums[a]==0)nums[a]=1;
        }
        for(int i:nums){
            ans+=i;
        }
        return ans;
    }
};