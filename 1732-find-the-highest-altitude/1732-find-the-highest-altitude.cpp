class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int a=0;
        for(int i:gain){
            a+=i;
            ans=max(a,ans);
        }
        return ans;
    }
};