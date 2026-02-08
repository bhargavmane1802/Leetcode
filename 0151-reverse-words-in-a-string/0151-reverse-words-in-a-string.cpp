class Solution {
public:
    void rev(string & s,int i,int j){
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    string reverseWords(string s) {
        int x=0;
        while(s[x]==' ')x++;
        s=s.substr(x,s.size());
        x=s.size()-1;
        while(s[x]==' ')x--;
        s=s.substr(0,x+1);
        x=1;
        while(x<s.size()){
            if(s[x]==' ' && s[x]==s[x-1] ){
                s=s.substr(0,x)+s.substr(x+1,s.size());
                x--;
            }
            x++;
        }
        int i=0;
        int j=0;
        while(j<s.size()){
            if(s[j]==' '){
                rev(s,i,j-1);
                i=j+1;
                j=j+1;
            }
            else{
                j++;
            }
        }
        rev(s,i,j-1);
        rev(s,0,s.size()-1);
        return s;
    }
};