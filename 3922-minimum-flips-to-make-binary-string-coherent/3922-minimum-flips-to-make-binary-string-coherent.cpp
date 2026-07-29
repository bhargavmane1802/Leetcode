
class Solution {
public:
    int minFlips(string s) {
        int f[2] = {0, 0};
        for (auto &c : s)
            f[c & 1]++;

        if (!f[0] || !f[1]) return 0;

        return min(
            f[0],
            f[1] - (s.front() & s.back() & 1) - 1 //f[1] - (1 or 2)
        );
    }
};

    //    int minFlips(string s) {
    //     int n = s.length();
    //     if (n < 3) return 0;
    //     int cnt0 = count(s.begin(), s.end(), '0');
    //     int cnt1 = n - cnt0;
    //     int res1 = cnt0;
    //     int res2 = max(cnt1 - 1, 0);
    //     int res3 = cnt1 - (s[0] - '0') - (s[n - 1] - '0');
    //     return min({res1, res2, res3});
    // }