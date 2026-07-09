class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>merge(n);
        int x=0;
        merge[0]=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                x++;
            }
            merge[i]=x;
        }
        n=queries.size();
        vector<bool>ans(n);
        x=0;
        for(auto i:queries){
            if(merge[i[0]]==merge[i[1]])ans[x]=true;
            else ans[x]=false;
            x++;
        }
        return ans;

    }
};