class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        string m1="";
        string t="";
        string m2="";
        string m3="";
        string m4="";
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    m1.push_back('1');
                }
                else{
                    m1.push_back('0');
                }
                if(target[i][j]==1){
                    t.push_back('1');
                }
                else{
                    t.push_back('0');
                }
                if(mat[n - 1 - j][i]==1){
                    m2.push_back('1');
                }
                else{
                    m2.push_back('0');
                }
                 if(mat[n - 1 - i][n - 1 - j]==1){
                    m3.push_back('1');
                }
                else{
                    m3.push_back('0');
                }
                 if(mat[j][n - 1 - i]==1){
                    m4.push_back('1');
                }
                else{
                    m4.push_back('0');
                }
            }
        }
        if(m1==t || m2==t ||m3==t ||m4==t)return true;
        return false;
        
    }
};