class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>num1;
        unordered_set<int>num2;
        vector<vector<int>>ans(2);
        for(int i:nums1)num1.insert(i);
        for(int i:nums2)num2.insert(i);
        for(int i:nums1){
            if(num1.find(i)!=num1.end() && num2.find(i)!=num2.end()){
                num1.erase(i);
                num2.erase(i);
            }
            if(num1.find(i)!=num1.end()){
                num1.erase(i);
                ans[0].push_back(i);
            }
        }
        for(int i:nums2){
            if(num2.find(i)!=num2.end()){
                num2.erase(i);
                ans[1].push_back(i);
            }
        }
        return ans;
    }
};