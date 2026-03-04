class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>row(n,-1);
        unordered_map<int,int>col;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    if(row[i]==-1)row[i]=j;
                    else if(row[i]==-2){row[i]==-2;}
                    else{row[i]=-2;}
                    col[j]++;
                }
            }
        }
        int ans=0;
        for(int i:row){
            if(i!=-1 && i!=-2 && col[i]<=1){
                ans++;
            }
        }
        return ans;
    }
};