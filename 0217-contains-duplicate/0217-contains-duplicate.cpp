class Solution {
public:
    bool containsDuplicate(vector<int>& temp) {
        unordered_set<int>nums;
        for(int i:temp){
            if(nums.find(i)!=nums.end())return true;
            nums.insert(i);
        }
        return false;
    }
};