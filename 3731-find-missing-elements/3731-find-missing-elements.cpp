class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int l=nums[0];
        int r=nums[0];
        for(int i:nums){
            l=min(l,i);
            r=max(i,r);
        }
        vector<int>temp(r-l+1);
        for(int i:nums){
            temp[i-l]=1;
        }
        vector<int>ans;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==0)ans.push_back(i+l);
        }
        return ans;
    }
};