class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>temp(26);
        for(char c:s){
            temp[c-'a']++;
        }
        string ans="";
        char x='1';
        for(int i=0;i<26;i++){
            if(temp[i]%2==1)x='a'+i;
            int n=temp[i]/2;
            while(n>0){
                ans+=('a'+i);
                n--;
            }
        }
        string a=ans;
        reverse(a.begin(),a.end());
        if(x!='1'){
            ans.push_back(x);
        }
        ans=ans+a;
        return ans;
        
    }
};