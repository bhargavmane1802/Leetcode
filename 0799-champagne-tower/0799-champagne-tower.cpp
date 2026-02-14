class Solution {
public:
    double champagneTower(int w, int r, int c) {
        vector<vector<double>>dp;
        int s=1;
        vector<double>t(1,w);
        dp.push_back(t);
        while(true){
            bool temp=false;
            vector<double>row(s+1);
            for(int i=0;i<s;i++){
                double curr_w=0;
                if(dp[s-1][i]>1.0){
                    temp=true;
                    curr_w=dp[s-1][i]-1;
                    dp[s-1][i]=1;
                }
                row[i]+=curr_w/2;
                row[i+1]+=curr_w/2;
            }
            s++;
            dp.push_back(row);
            if(s>r+1)return dp[r][c];
            if(!temp)break;
        }
        return 0;
    }
};