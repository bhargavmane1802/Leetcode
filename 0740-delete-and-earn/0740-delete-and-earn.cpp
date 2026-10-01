class Solution {
public:
    int solve(vector<vector<int>>&temp,int idx,int limit,vector<vector<int>>&dp){
        if(idx>=temp.size()){
            return 0;
        }
        if(temp[idx][0]>limit){
            if(dp[idx][0]!=-1)return dp[idx][0];
            int a=(temp[idx][0]*temp[idx][1])+solve(temp,idx+1,temp[idx][0]+1,dp);
            int b=solve(temp,idx+1,limit,dp);
            return dp[idx][0]=max(a,b);
        }
        else{
            if(dp[idx][1]!=-1)return dp[idx][1];
            return dp[idx][1]=solve(temp,idx+1,limit,dp);
        }
    }
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>mp;
        for(int i:nums)mp[i]++;
        int n=nums.size();
        vector<vector<int>>temp;
        vector<vector<int>>dp(n,{-1,-1});
        for(auto x:mp){
            cout<<x.first<<" "<<x.second<<endl;
            temp.push_back({x.first,x.second});
        }
        return solve(temp,0,0,dp);

    }
};