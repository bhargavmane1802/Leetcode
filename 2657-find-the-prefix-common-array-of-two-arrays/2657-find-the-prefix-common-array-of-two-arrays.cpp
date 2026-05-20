class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>freq(n+1);   
        vector<int>ans(n);
        int c=0;
        for(int i=0;i<n;i++){
            if(A[i]==B[i])c++;
            else{
                freq[A[i]]++;
                freq[B[i]]++;
                if(freq[A[i]]==2)c++;
                if(freq[B[i]]==2)c++;   
            }
            ans[i]=c;
        }
        return ans;
    }
};