class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n);
        for(auto x:bookings){
            for(int i=x[0]-1;i<=x[1]-1;i++){
                ans[i]+=x[2];
            }
        }
        return ans;
    }
};