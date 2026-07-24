class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;
        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;
        for (int v : nums) {
            auto ndp = dp;
            for (int cnt = 0; cnt <= 3; cnt++) {
                for (int xr = 0; xr < MAXX; xr++) {
                    if (!dp[cnt][xr]) continue;
                    if (cnt + 1 <= 3)
                        ndp[cnt + 1][xr ^ v] = true;
                    if (cnt + 2 <= 3)
                        ndp[cnt + 2][xr] = true;

                    if (cnt + 3 <= 3)
                        ndp[cnt + 3][xr ^ v] = true;
                }
            }
            dp.swap(ndp);
        }
        int ans = 0;
        for (bool ok : dp[3]) {
            if (ok) ans++;
        }
        return ans;
    }
};