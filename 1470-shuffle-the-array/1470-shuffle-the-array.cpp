class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans(2*n);
        // for(int i=0;i<n;i++){
        //     ans.push_back(nums[i]);
        //     ans.push_back(nums[i+n]);
        // }
        // return ans;
        int x=0;
        for(int i=0;i<n*2;i+=2){
            ans[i]=nums[x];
            ans[i+1]=nums[x+n];
            x++;
        }
        return ans;
    }
};