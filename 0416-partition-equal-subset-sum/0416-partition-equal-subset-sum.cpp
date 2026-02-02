class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums)sum+=i;
        if(sum%2==1)return false;
        sum=sum/2;
        vector<int>visited(sum+1,0);
        visited[0]=1;
        for(int i:nums){
            for (int j = sum; j >= i; j--) {
                if (visited[j - i] == 1) {
                    visited[j] = 1;
                }
            }
        }
        if(visited[visited.size()-1]==1)return true;
        return false;

    }
};