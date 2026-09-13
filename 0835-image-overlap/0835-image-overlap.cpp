class Solution {
public:
    int solve(vector<vector<int>>& img1, vector<vector<int>>& img2,int a,int b){
        int n=img1.size();
        int ans=0;
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=i+a;
                int y=j+b;
                if(x>=0 && y>=0 && x<n && y<n){
                    if(img1[x][y]==1 && img2[i][j]==1)count++;
                }
            }
        }
        ans=max(ans,count);
        count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=i-a;
                int y=j+b;
                if(x>=0 && y>=0 && x<n && y<n){
                    if(img1[x][y]==1 && img2[i][j]==1)count++;
                }
            }
        }
        ans=max(ans,count);
        count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=i+a;
                int y=j-b;
                if(x>=0 && y>=0 && x<n && y<n){
                    if(img1[x][y]==1 && img2[i][j]==1)count++;
                }
            }
        }
        ans=max(ans,count);
        count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=i-a;
                int y=j-b;
                if(x>=0 && y>=0 && x<n && y<n){
                    if(img1[x][y]==1 && img2[i][j]==1)count++;
                }
            }
        }
        ans=max(ans,count);
        return ans;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans=0;
        int n=img1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,solve(img1,img2,i,j));
            }
        }
        return ans;
    }
};