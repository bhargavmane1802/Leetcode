class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        k=k%m;
        if(k==0)return true;
        int l=k;
        int r=m-k;
        vector<int>right(r);
        vector<int>left(l);
        for(int i=0;i<n;i++){
            int x=0;
            while(x<l){
                left[x]=mat[i][x];
                x++;
            }
            while(x<m){
                right[x-l]=mat[i][x];
                x++;
            }
            x=0;
            while(x<r){
                ans[i][x]=right[x];
                x++;
            }
            while(x<m){
                ans[i][x]=left[x-r];
                x++;
            }
        }
        return (mat==ans);



        // int s=n*m;
        // vector<int>temp(s);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         temp[(i*n)+j]=mat[i][j];
        //     }
        // }

        
    }
};