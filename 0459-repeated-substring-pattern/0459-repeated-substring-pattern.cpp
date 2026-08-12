class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        vector<int>nums(n);
        int j=0;
        for(int i=1;i<n;i++){
            while(j>0 && s[i]!=s[j]){
                j=nums[j-1];
            }
            if(s[i]==s[j])j++;
            nums[i]=j;
        }
        int x=nums.back();
        int y=n-x;
        return x && !(n%y);
    }
};