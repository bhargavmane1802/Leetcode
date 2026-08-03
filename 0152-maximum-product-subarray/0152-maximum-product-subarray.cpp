class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p=1;
        vector<int>l;
        int n=nums.size();
        vector<int>r(n);

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                l.push_back(0);
                p=1;
            }
            else{
                p*=nums[i];
                l.push_back(p);
            }
        }
        p=1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0){
                r[i]=0;
                p=1;
            }
            else{
                p*=nums[i];
                r[i]=p;
            }
        }
        int mx=nums[0];
        for(int i=0;i<n;i++){
            mx=max(max(l[i],r[i]),mx);
        }
        return mx;
    }
};