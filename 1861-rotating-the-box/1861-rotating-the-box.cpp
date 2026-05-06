class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size();
        int m=boxGrid[0].size();
        for(int i=0;i<n;i++){
            int  b=m-1;
            for(int j=m-1;j>=0;j--){
                if('.'==boxGrid[i][j])continue;
                else if('*'==boxGrid[i][j]){
                    b=j-1;
                }
                else{
                    swap(boxGrid[i][j],boxGrid[i][b]);
                    b--;
                }

            }
        }
        vector<vector<char>>ans(m,vector<char>(n,'.'));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[j][n-1-i]=boxGrid[i][j];
            }
        }
        return ans;
    }
};