class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int a=0;
        int c=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                return false;
            }
            if(a==0){
                if(nums[i]>nums[i+1]){
                    if(i==0){
                        return false;
                    }
                    a=1;
                    c++;
                }
            }
            else{
                if(nums[i]<nums[i+1]){
                    a=0;
                    c++;
                }
            }
        }
        if(c==2){
            return true;
        }
        else{
            return false;
        }
            
        
    }
};