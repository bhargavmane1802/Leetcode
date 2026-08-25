class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>temp;
        for(int i:nums){
            temp.insert(i);
        }
        int x=k;
        while(temp.find(x)!=temp.end())x+=k;
        return x;
    }
};