class Solution {
public:
    string reverseVowels(string s) {
        int l=0;
        int r=s.size()-1;
        unordered_set<char>temp={'a','e','i','o','u','U','A','E','I','O'};
        while(l<r){
            if(temp.find(s[l])==temp.end())l++;
            else{
                while(l<r && temp.find(s[r])==temp.end())r--;
                swap(s[l],s[r]);
                r--;l++;
            }
        }
        return s;
    }
};