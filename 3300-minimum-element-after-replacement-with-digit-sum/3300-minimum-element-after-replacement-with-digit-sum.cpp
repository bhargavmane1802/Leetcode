class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int x;
        int m=INT_MAX;
        for(int i=0;i<n;i++){
            int x=nums[i];
            nums[i]=0;
            while(x>0){
                nums[i]+=(x%10);
                x/=10;
            }
            m=min(m,nums[i]);
        }
        return m;
    }
};