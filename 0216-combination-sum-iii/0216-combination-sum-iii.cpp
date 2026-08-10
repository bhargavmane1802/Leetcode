class Solution {
public:
    void solve(int k, int n ,vector<int>&nums,vector<vector<int>>&ans,int idx,int sum,vector<int>temp){
        if( temp.size()==k && sum==n ){
            ans.push_back(temp);
            return ;
        }
        if(temp.size()>=k || sum>n)return;
        for(int i=idx+1;i<9;i++){
            if(sum+nums[i]>n)return;
            temp.push_back(nums[i]);
            sum+=nums[i];
            solve(k,n,nums,ans,i,sum,temp);
            sum-=nums[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        vector<vector<int>>ans;
        solve(k,n,nums,ans,-1,0,{});
        return ans;
    }
};