class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>l(26);
        vector<int>u(26);
        int ans=0;
        for(char i:word){
            if(i>='a' && i<='z'){
                if(l[i-'a']==-1)continue;
                if(u[i-'a']==0)l[i-'a']++;
                else l[i-'a']=-1;
            }
            else{
                u[i-'A']=1;
            }
        }
        for(int i=0;i<26;i++){
            if(l[i]>0 && u[i]==1)ans++;
        }
        return ans;
        
    }
};