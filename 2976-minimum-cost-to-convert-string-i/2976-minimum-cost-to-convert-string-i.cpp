class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& cost) {
        vector<vector<long long>>nums(26,vector<long long>(26,INT_MAX));
        int n=cost.size();
        for(int i=0;i<n;i++){
            int x=o[i]-'a';
            int y=c[i]-'a';
            long long temp = (long long)cost[i];
            nums[x][y]=min(nums[x][y],temp);
        }
        for(int i=0;i<26;i++){
            nums[i][i]=0;
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    nums[i][j]=min(nums[i][k]+nums[k][j],nums[i][j]);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<s.size();i++){
            int x=s[i]-'a';
            int y=t[i]-'a';
            if(s[i]!=t[i]){
                if(nums[x][y]==INT_MAX)return -1;
                ans+=nums[x][y];
            }

        }
        return ans;
    }
};