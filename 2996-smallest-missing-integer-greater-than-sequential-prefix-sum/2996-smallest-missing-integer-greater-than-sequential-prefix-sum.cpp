class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int>temp;
        for(int i:nums){
            temp.insert(i);
        }
        int n=nums.size();
        int x=nums[0];
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }
            else break;
            x=max(x,sum);
        }
        cout<<x;
        while(temp.find(x)!=temp.end()){
            x++;
        }
        return x;
    }
};