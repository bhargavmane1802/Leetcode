class Solution {
public:

    int solve(vector<int>&nums, int idx,int limit,vector<pair<int,int>>&s){
        vector<int>temp;
        int t=idx;
        for(int i=idx;i<s.size();i++){
            if(s[i].first>s[t].first+limit)break;
            t=i;
            temp.push_back(s[i].second);
        }
        sort(temp.begin(),temp.end());
        int a=idx;
        for(int i:temp){
            nums[i]=s[a].first;
            a++;
        }
        return a-1;

    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>s(n);
        for(int i=0;i<n;i++){
            s[i]={nums[i],i};
        }
        sort(s.begin(),s.end());
        for(int i=0;i<n;i++){
            i=solve(nums,i,limit,s);
        }
        return nums;

    }
};