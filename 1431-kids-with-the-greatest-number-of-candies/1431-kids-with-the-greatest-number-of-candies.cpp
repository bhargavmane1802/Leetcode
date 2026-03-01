class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx=0;
        for(int i:candies){
            mx=max(mx,i);
        }
        int n=candies.size();
        vector<bool>ans(n,true);
        for(int i=0;i<n;i++){
            if(mx>candies[i]+extraCandies){
                ans[i]=false;
            }
        }
        return ans;
    }
};