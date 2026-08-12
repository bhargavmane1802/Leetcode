class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>temp;
        int x=0;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            temp[nums[i]]++;
            while(temp[nums[i]]>k){
                temp[nums[x]]--;
                x++;
            }
            ans=max(ans,i-x+1);
        }
        return ans;
    }
};