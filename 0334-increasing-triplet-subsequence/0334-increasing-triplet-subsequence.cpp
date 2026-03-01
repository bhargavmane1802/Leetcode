class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int l=INT_MAX;
        int r=INT_MAX;
        for(int i:nums){
            if(i<l)l=i;
            else if(i==l)continue;
            else if(i<r)r=i;
            else if(i==r)continue;
            else return true;
        }
        return false;
        
    }
};