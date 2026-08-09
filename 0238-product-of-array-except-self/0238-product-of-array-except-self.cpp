class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int c=0;
        int p=1;
        int n=nums.size();
        int x=-1;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            if(c==0 && nums[i]==0){
                c++;
                x=i;
            }
            else if(c==1 && nums[i]==0){
                c++;
                break;
            }
            else p*=nums[i];
        }
        if(c==2)return ans;
        if(c==0){
            for(int i=0;i<n;i++){
                ans[i]=(p/nums[i]);
            }
            return ans;
        }
        ans[x]=p;
        return ans;
        
    }
};