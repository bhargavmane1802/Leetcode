class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1)return '0';
        string s="0";
        while(n>1){
            n--;
            string temp="";
            for(char i:s){
                if(i=='1')temp.push_back('0');
                else temp.push_back('1');
            }
            reverse(temp.begin(),temp.end());
            s=s+"1"+temp;
        }
        return s[k-1];
        
    }
};