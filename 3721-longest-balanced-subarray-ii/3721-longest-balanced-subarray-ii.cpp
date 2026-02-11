class Solution {
    struct SegmentTree {
        int n;
        vector<int> mn, mx, lazy;

        SegmentTree(int n) : n(n) {
            mn.resize(4 * n, 0);
            mx.resize(4 * n, 0);
            lazy.resize(4 * n, 0);
        }
        void push(int node) {
            if (lazy[node] != 0) {
                lazy[2 * node] += lazy[node];
                mn[2 * node] += lazy[node];
                mx[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
                mn[2 * node + 1] += lazy[node];
                mx[2 * node + 1] += lazy[node];
                lazy[node] = 0;
            }
        }
        void update(int node, int start, int end, int l, int r, int val) {
            if (l > end || r < start) return;
            if (l <= start && end <= r) {
                mn[node] += val;
                mx[node] += val;
                lazy[node] += val;
                return;
            }
            push(node);
            int mid = (start + end) / 2;
            update(2 * node, start, mid, l, r, val);
            update(2 * node + 1, mid + 1, end, l, r, val);
            mn[node] = min(mn[2 * node], mn[2 * node + 1]);
            mx[node] = max(mx[2 * node], mx[2 * node + 1]);
        }
        int queryLeftmostZero(int node, int start, int end, int limit) {
            if (start > limit) return -1;
            if (mn[node] > 0 || mx[node] < 0) return -1;
            if (start == end) {
                return (mn[node] == 0) ? start : -1;
            }
            push(node);
            int mid = (start + end) / 2;            
            int res = queryLeftmostZero(2 * node, start, mid, limit);
            if (res != -1) return res;
            return queryLeftmostZero(2 * node + 1, mid + 1, end, limit);
        }
    };

public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        SegmentTree st(n);
        unordered_map<int, int> lastPos;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            int prev = lastPos.count(val) ? lastPos[val] : -1;
            int diff = (val % 2 == 0) ? 1 : -1;
            st.update(1, 0, n - 1, prev + 1, i, diff);
            lastPos[val] = i;
            int j = st.queryLeftmostZero(1, 0, n - 1, i);
            if (j != -1) {
                ans = max(ans, i - j + 1);
            }
        }

        return ans;
    }
};