class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        vector<int>temp(26);
        for(char c:s1){
            temp[c-'a']++;
        }
        vector<int>nums(26);
        for(int i=0;i<s1.size()-1;i++){
            nums[s2[i]-'a']++;
        }
        int j=0;
        for(int i=s1.size()-1;i<s2.size();i++){
            nums[s2[i]-'a']++;
            if(temp==nums)return true;
            nums[s2[j]-'a']--;
            j++;
        }
        return false;
    }
};