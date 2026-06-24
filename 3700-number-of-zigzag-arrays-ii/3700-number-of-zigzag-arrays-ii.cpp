class Solution {
public:
    static const int MOD = 1'000'000'007;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                long long aik = A[i][k];
                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;
                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<long long> multiply(const Matrix& A, const vector<long long>& v) {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long cur = 0;
            for (int j = 0; j < n; j++) {
                cur = (cur + A[i][j] * v[j]) % MOD;
            }
            res[i] = cur;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        long long m = r - l + 1;

        if (n == 1) return (int)m;

        int S = 2 * m;

        // States:
        // [0 .. m-1]     : next comparison must be UP
        // [m .. 2m-1]    : next comparison must be DOWN
        Matrix T(S, vector<long long>(S, 0));

        for (int x = 0; x < m; x++) {
            // UP(x) -> DOWN(y) for y > x
            for (int y = x + 1; y < m; y++) {
                T[m + y][x] = 1;
            }

            // DOWN(x) -> UP(y) for y < x
            for (int y = 0; y < x; y++) {
                T[y][m + x] = 1;
            }
        }

        vector<long long> vec(S, 1); // all starting values, both directions
        long long e = n - 1;

        Matrix P = T;

        while (e > 0) {
            if (e & 1) vec = multiply(P, vec);
            e >>= 1;
            if (e) P = multiply(P, P);
        }

        long long ans = 0;
        for (long long x : vec) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};