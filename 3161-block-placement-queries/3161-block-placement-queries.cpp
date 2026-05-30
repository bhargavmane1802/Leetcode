class Solution {
public:
    static constexpr int MX = 50001;

    struct SegTree {
        vector<int> mx, lazy;

        SegTree(int n) {
            mx.resize(4 * n);
            lazy.resize(4 * n);
        }

        void build(int idx, int l, int r, const vector<int>& a) {
            if (l == r) {
                mx[idx] = a[l];
                return;
            }

            int mid = (l + r) >> 1;

            build(idx << 1, l, mid, a);
            build(idx << 1 | 1, mid + 1, r, a);

            mx[idx] = max(mx[idx << 1], mx[idx << 1 | 1]);
        }

        void push(int idx) {
            if (!lazy[idx]) return;

            int v = lazy[idx];

            mx[idx << 1] += v;
            mx[idx << 1 | 1] += v;

            lazy[idx << 1] += v;
            lazy[idx << 1 | 1] += v;

            lazy[idx] = 0;
        }

        void rangeAdd(int idx, int l, int r,
                      int ql, int qr, int val) {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                mx[idx] += val;
                lazy[idx] += val;
                return;
            }

            push(idx);

            int mid = (l + r) >> 1;

            rangeAdd(idx << 1, l, mid, ql, qr, val);
            rangeAdd(idx << 1 | 1, mid + 1, r, ql, qr, val);

            mx[idx] = max(mx[idx << 1], mx[idx << 1 | 1]);
        }

        int queryMax(int idx, int l, int r,
                     int ql, int qr) {
            if (ql > r || qr < l) return 0;

            if (ql <= l && r <= qr) return mx[idx];

            push(idx);

            int mid = (l + r) >> 1;

            return max(
                queryMax(idx << 1, l, mid, ql, qr),
                queryMax(idx << 1 | 1, mid + 1, r, ql, qr)
            );
        }
    };

    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> obstacles;

        for (auto& q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }

        obstacles.insert(MX); // sentinel

        vector<int> d(MX);

        int last = 0;

        for (int p : obstacles) {
            for (int i = last; i < p; i++) {
                d[i] = p - i;
            }
            last = p;
        }

        SegTree seg(MX);
        seg.build(1, 0, MX - 1, d);

        obstacles.insert(0); // dummy obstacle

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; --i) {
            auto& q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                if (x < sz) {
                    ans.push_back(false);
                    continue;
                }

                int best = seg.queryMax(
                    1, 0, MX - 1,
                    0, x - sz
                );

                ans.push_back(best >= sz);
            } else {
                int p = q[1];

                auto it = obstacles.find(p);

                int prv = *std::prev(it);
                int nxt = *std::next(it);

                seg.rangeAdd(
                    1, 0, MX - 1,
                    prv, p - 1,
                    nxt - p
                );

                obstacles.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};