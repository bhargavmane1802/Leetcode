class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>store(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
                store[i][j]=sum;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                sum+=store[j][i];
                if(sum<=k){
                    ans++;
                }
                else{
                    break;
                }
            }
        }
        return ans;
        
    }
};