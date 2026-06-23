class Solution {
public:
    static constexpr long long MOD = 1'000'000'007LL;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m, 1), down(m, 1);

        for (int len = 1; len < n; ++len) {
            vector<long long> newUp(m, 0), newDown(m, 0);

            long long pref = 0;
            for (int y = 0; y < m; ++y) {
                newDown[y] = pref;
                pref = (pref + up[y]) % MOD;
            }

            long long suff = 0;
            for (int y = m - 1; y >= 0; --y) {
                newUp[y] = suff;
                suff = (suff + down[y]) % MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;
        for (int i = 0; i < m; ++i) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};