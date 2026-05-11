class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            vector<int>temp;
            while(x>0){
                temp.push_back(x%10);
                x=x/10;
            }
            reverse(temp.begin(),temp.end());
            for(int j=0;j<temp.size();j++){
                ans.push_back(temp[j]);
            }
        }
    return ans;
    }
};