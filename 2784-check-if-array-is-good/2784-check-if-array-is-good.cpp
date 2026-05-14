class Solution {
public:
    bool isGood(vector<int>& nums) {
        // brute force 
        int n=nums.size();
        vector<int>check(n);
        if(n==1)return false;
        for(int i:nums){
            if(i>=n)return false;
            check[i]++;
            if((i==n-1 && check[i]>2)||(i!=n-1 && check[i]>1))return false;
        }
        return true;
    }
};