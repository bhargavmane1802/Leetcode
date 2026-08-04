class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int n=nums.size();
        int x=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                x++;
            }
            else{
                while(x<nums[i]){
                    ans.push_back(x);
                    x++;
                }
                x++;
            }
        }
        return ans;
    }
};