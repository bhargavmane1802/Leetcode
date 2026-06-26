class Fenwick {
public:
    vector<int> bit;
    Fenwick(int n) {
        bit.assign(n + 1, 0);
    }

    void add(int idx, int val) {
        while (idx < bit.size()) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int sum(int idx) {
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick ft(vals.size());

        long long ans = 0;

        for (int x : pref) {
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
            ans += ft.sum(idx - 1);

            ft.add(idx, 1);
        }

        return ans;
    }
};