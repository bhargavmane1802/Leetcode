class Solution {
public:
    int coinChange(vector<int>& coins, int a) {
        if(a==0)return 0;
        int n=coins.size();
        vector<int>ans(a+1,100000000);
        ans[0]=0;
        for(int i:coins){
            if(i>a)continue;
            for(int j=0;j<=a-i;j++){
                ans[i+j]=min(ans[i+j],ans[j]+1);
            }
        }
        if(ans.back()==100000000)return -1;
        return ans.back();
    }
};