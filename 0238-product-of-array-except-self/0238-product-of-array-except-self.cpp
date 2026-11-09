class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int czero=0;
        int p=1;
        int n=nums.size();
        int m=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){czero++;m=i;}
            if(czero==2)break;
            if(nums[i]!=0)p*=nums[i];
        }
        if(czero==2){
            vector<int>ans(n,0);
            return ans;
        }
        else if(czero==1){
            vector<int>ans(n,0);
            ans[m]=p;
            return ans;
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=p/nums[i];
        }
        return ans;

    }
};