class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans(n,0);
        unordered_set<int>a;
        unordered_set<int>b;
        for(int i=0;i<n;i++){
            if(i==0 ){
                if(A[i]==B[i])
                ans[i]=1;
                else{
                    a.insert(A[i]);
                    b.insert(B[i]);
                }
            }
            else if(A[i]==B[i]){
                ans[i]=1+ans[i-1];
            }
            else {
                ans[i]=ans[i-1];
                if(a.find(B[i])!=a.end())ans[i]++;
                if(b.find(A[i])!=b.end())ans[i]++;
                a.insert(A[i]);
                b.insert(B[i]);
            }
        }
        return ans;
    }
};