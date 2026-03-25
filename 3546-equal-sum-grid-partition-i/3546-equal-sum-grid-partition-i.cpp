class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>row(n);
        vector<int>col(m);
        long long tsum=0;
        for(int i=0;i<n;i++){
            long long s=0;
            for(int j=0;j<m;j++){
                s+=grid[i][j];
                tsum+=grid[i][j];
            }
            row[i]=s;
        }if(tsum%2==1)return false;
        for(int i=0;i<m;i++){
            long long s=0;
            for(int j=0;j<n;j++){
                s+=grid[j][i];
            }
            col[i]=s;
        }
        long long x=0;
        tsum/=2;
        for(int i=0;i<n;i++){
            x+=row[i];
            if(x==tsum)return true;
        }
        x=0;
        for(int i=0;i<m;i++){
            x+=col[i];
            if(x==tsum)return true;
        }
        return false;

        
    }
};