class Solution {
public:
    string shortestPalindrome(string s) {
        string q=s;
        reverse(s.begin(),s.end());
        swap(q,s);
        string temp=s+"#"+q;
        int n=temp.size();
        vector<int>nums(n);
        int j=0;
        for(int i=1;i<n;i++){
            while(j>0 && temp[i]!=temp[j]){
                j=nums[j-1];
            }
            if(temp[i]==temp[j])j++;
            nums[i]=j;
        }
        int x= nums.back();
        string a=s.substr(x,s.size()-x);
        reverse(a.begin(),a.end());
        return a+s;
        

    }
};