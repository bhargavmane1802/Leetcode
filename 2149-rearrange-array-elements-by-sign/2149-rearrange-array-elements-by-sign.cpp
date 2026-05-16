class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>p;
        vector<int>n;
        int x=nums.size();
        for(int i=0;i<x;i++){
            if(nums[i]>0)p.push_back(nums[i]);
            else n.push_back(nums[i]);
        }
        vector<int>ans(x);
        int j=0;
        for(int i=0;i<x;i+=2){
            ans[i]=p[j];
            ans[i+1]=n[j];
            j++;
        }
        return ans;
    }
};