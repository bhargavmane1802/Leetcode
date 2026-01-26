class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(char i:s){
            if( (isalnum(i))){
                temp.push_back(tolower(i));
            }
        }
        int l=0;
        int r=temp.size()-1;
        while(l<=r){
            if(temp[l]==temp[r]){
                l++;r--;
            }
            else{
                return false;
            }
        }
        return true;

    }
};