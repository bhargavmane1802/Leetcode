class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;

        int n = s.size();

        // pref[i] = {sum of non-zero digits till i-1, count of non-zero digits}
        vector<pair<long long,int>> pref(n + 1);

        string curr;
        long long sum = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                curr.push_back(s[i]);
                sum += s[i] - '0';
                cnt++;
            }
            pref[i + 1] = {sum, cnt};
        }

        int m = curr.size();

        vector<long long> pow10(m + 1, 1), hash(m + 1, 0);

        for (int i = 0; i < m; i++) {
            pow10[i + 1] = (pow10[i] * 10) % MOD;
            hash[i + 1] = (hash[i] * 10 + (curr[i] - '0')) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            long long digitSum = pref[r + 1].first - pref[l].first;

            if (digitSum == 0) {
                ans.push_back(0);
                continue;
            }

            int L = pref[l].second;
            int R = pref[r + 1].second;
            int len = R - L;

            long long num =
                (hash[R] - hash[L] * pow10[len] % MOD + MOD) % MOD;

            ans.push_back((num * digitSum) % MOD);
        }

        return ans;
    }
};