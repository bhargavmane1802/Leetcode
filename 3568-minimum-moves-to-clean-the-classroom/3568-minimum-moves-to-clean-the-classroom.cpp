class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();
        int sr = 0, sc = 0;
        int litterCount = 0;
        vector<vector<int>> id(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount;
                    litterCount++;
                }
            }
        }
        if (litterCount == 0)
            return 0;
        int totalMasks = 1 << litterCount;
        int targetMask = totalMasks - 1;
        vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(m,vector<vector<bool>>(energy + 1, vector<bool>(totalMasks, false))) );
        queue<tuple<int, int, int, int>> q;
        q.push({sr, sc, energy, 0});
        visited[sr][sc][energy][0] = true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int moves = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, currEnergy, mask] = q.front();
                q.pop();
                if (mask == targetMask)
                    return moves;
                if (currEnergy == 0)
                    continue;
                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                        continue;
                    if (classroom[nr][nc] == 'X')
                        continue;
                    int nextEnergy;
                    int nextMask = mask;
                    if (classroom[nr][nc] == 'R')
                        nextEnergy = energy;
                    else
                        nextEnergy = currEnergy - 1;
                    if (classroom[nr][nc] == 'L') {
                        int index = id[nr][nc];
                        nextMask |= (1 << index);
                    }
                    if (visited[nr][nc][nextEnergy][nextMask])
                        continue;
                    visited[nr][nc][nextEnergy][nextMask] = true;
                    q.push({nr, nc, nextEnergy, nextMask});
                }
            }
            moves++;
        }
        return -1;
    }
};