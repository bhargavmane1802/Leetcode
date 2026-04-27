class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ports = {
            {}, {2, 3}, {0, 1}, {2, 1}, {3, 1}, {2, 0}, {3, 0}
        };
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int opposite[] = {1, 0, 3, 2};

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) return true;

            for (int dir : ports[grid[r][c]]) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    bool canEnter = false;
                    for (int nextDir : ports[grid[nr][nc]]) {
                        if (nextDir == opposite[dir]) {
                            canEnter = true;
                            break;
                        }
                    }

                    if (canEnter) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }
};