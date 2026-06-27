class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;

        for (int x : nums)
            cnt[x]++;

        int ans = 1;

        if (cnt.count(1)) {
            ans = cnt[1];
            if (ans % 2 == 0) ans--;
        }

        for (auto &[x, f] : cnt) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;
            
            // Removed the faulty break condition
            while (cnt.contains(cur) && cnt[cur] >= 2) {
                len += 2;
                cur *= cur; 
            }

            if (cnt.contains(cur) && cnt[cur] >= 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};