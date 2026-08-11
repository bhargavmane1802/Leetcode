class Solution {
public:
    int missingInteger(vector<int>& nums) {
        vector<int>temp(55);
        int n=nums.size();
        int x=nums[0];
        temp[nums[0]]=1;
        int a=0;
        for(int i=1;i<n;i++){
            if( a==0 && nums[i]==nums[i-1]+1){
                x+=nums[i];
            
            }
            else a=1;
            temp[nums[i]]=1;
        }
        if(x>50)return x;
        while(temp[x]==1)x++;
        return x;
    }
};