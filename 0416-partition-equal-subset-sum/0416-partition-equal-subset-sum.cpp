class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i:nums)sum+=i;
        if(sum%2==1)return false;
        sum/=2;
        vector<int>total(sum+1);
        total[0]=1;
        for(int i:nums){
            for(int j=sum;j-i>=0;j--){
                if(total[j-i]==1)total[j]=1;
            }
        }
        if(total.back()==1)return true;
        return false;
    }
};