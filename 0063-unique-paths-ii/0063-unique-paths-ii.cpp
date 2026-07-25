class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        if(nums[n-1][m-1]==1)return 0;
        ans[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]==1)continue;
                if(i!=n-1 && nums[i+1][j]!=1){
                    ans[i+1][j]+=ans[i][j];
                }
                if(j!=m-1 && nums[i][j+1]!=1){
                    ans[i][j+1]+=ans[i][j];
                }
            }
        }
        return ans[n-1][m-1];
    }
};