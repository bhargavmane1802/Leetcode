class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;
    Node dp[20][2][11][11];
    bool vis[20][2][11][11];

    Node dfs(int pos, int started, int last1, int last2, bool tight) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][started][last1][last2]) {
            return dp[pos][started][last1][last2];
        }

        int limit = tight ? (s[pos] - '0') : 9;

        long long totalCnt = 0;
        long long totalSum = 0;

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started) {
                if (d == 0) {
                    Node nxt = dfs(pos + 1, 0, 10, 10, ntight);
                    totalCnt += nxt.cnt;
                    totalSum += nxt.sum;
                } else {
                    Node nxt = dfs(pos + 1, 1, d, 10, ntight);
                    totalCnt += nxt.cnt;
                    totalSum += nxt.sum;
                }
            } else {
                if (last2 == 10) {
                    // Currently only one digit exists in the number.
                    Node nxt = dfs(pos + 1, 1, d, last1, ntight);
                    totalCnt += nxt.cnt;
                    totalSum += nxt.sum;
                } else {
                    // last1 is the middle digit of (last2, last1, d).
                    int add =
                        ((last1 > last2 && last1 > d) ||
                         (last1 < last2 && last1 < d))
                            ? 1
                            : 0;

                    Node nxt = dfs(pos + 1, 1, d, last1, ntight);

                    totalCnt += nxt.cnt;
                    totalSum += nxt.sum + 1LL * add * nxt.cnt;
                }
            }
        }

        Node res{totalCnt, totalSum};

        if (!tight) {
            vis[pos][started][last1][last2] = true;
            dp[pos][started][last1][last2] = res;
        }

        return res;
    }

    long long solve(long long n) {
        if (n < 0) return 0;

        s = to_string(n);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 0, 10, 10, true).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};