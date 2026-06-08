class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>front;
        vector<int>back;
        vector<int>ans(n,pivot);
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot)front.push_back(nums[i]);
            else if (nums[i]>pivot)back.push_back(nums[i]);
            else c++;
        }
        for(int i=0;i<front.size();i++)ans[i]=front[i];
        c+=front.size();
        for(int i=0;i<back.size();i++)ans[i+c]=back[i];
        return ans;
    }
};