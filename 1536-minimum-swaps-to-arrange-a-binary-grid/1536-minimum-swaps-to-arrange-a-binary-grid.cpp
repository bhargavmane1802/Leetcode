class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int  n=grid.size();
        vector<int>v1(n);
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0)c++;
                else{
                    break;
                }
            }
            v1[i]=c;
        }
        int ans=0;
        int temp=n-1;
        for(int i=0;i<n;i++){
           int x=i;
           while(x<n){
             if(v1[x]>=temp)break;
             x++;
           }
            if(x==n)return -1;
            while(x>i){
                swap(v1[x],v1[x-1]);
                x--;
                ans++;
            }
            temp--;
        }
        return ans;
    }
};