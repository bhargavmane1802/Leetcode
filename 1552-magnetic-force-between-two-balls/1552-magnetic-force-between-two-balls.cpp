class Solution {
public:
bool solve(vector<int>& nums,int m,int limit){
    int p=1;
    int x=0;
    for(int i=0;i<nums.size();i++){
        if(abs(nums[i]-nums[x])>=limit){
            p++;
            x=i;
        }
    }
    return p>=m;
}
    int maxDistance(vector<int>& nums, int m) {
        int n=nums.size();
        if(m>n)return -1;
        int mx=nums[0];
        int mn=nums[0];
        sort(nums.begin(),nums.end());
        int l=1;
        int r=nums[n-1]-nums[0];
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(nums,m,mid)){
               l=mid+1;
            }
            else r=mid-1;
        }
        return l-1;


        
    }
};