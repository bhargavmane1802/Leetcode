class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=0;
        int b=1;
        int ca=0;
        int cb=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(ca==0 && b!=nums[i]){
                a=nums[i];
                ca=1;
            }
            else if(a==nums[i])ca++;
            else if(cb==0){
                b=nums[i];
                cb=1;
            }
            else if(b==nums[i])cb++;
            else {
                ca--;
                cb--;
            }
        }
        vector<int>ans;
        ca=0;
        cb=0;
        for(int i:nums){
            if(a==i)ca++;
            else if(b==i)cb++;
        }
        if(ca>n/3)ans.push_back(a);
        if(cb>n/3)ans.push_back(b);
        return ans;
        
    }
};