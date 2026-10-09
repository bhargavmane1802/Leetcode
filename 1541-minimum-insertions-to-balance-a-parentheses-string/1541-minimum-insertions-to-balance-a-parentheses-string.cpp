class Solution {
public:
    int minInsertions(string s) {
        int a=0;
        int b=0;
        int n=s.size(),ans=0;
        vector<int>visited(n);
        for(int i=0;i<n;i++){
            if(a<=i)a=i+1;
            while(a<n && s[a]=='('){
                a++;
            }
            if(s[i]=='('){
                if(a>=n)ans+=2;
                else if(a==n-1){
                    visited[a]=1;
                    ans+=1;
                    a++;
                }
                else if(s[a+1]==')') {
                    visited[a]=1;
                    visited[a+1]=1;
                    a+=2;
                }
                else {
                    visited[a]=1;
                    ans+=1;
                    a++;
                }
            } 
            else {
                if(visited[i]==1)continue;
                else if(i==n-1) {
                    ans+=2;
                }else{
                    if(s[i+1]==')'){
                        visited[i+1]=1;
                        ans+=1;
                    }
                    else {
                        ans+=2;
                    }
                }
            }
        }
        return ans;
    }
};