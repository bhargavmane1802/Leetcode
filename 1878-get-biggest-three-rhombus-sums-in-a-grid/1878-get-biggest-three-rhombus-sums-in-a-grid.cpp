class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> sums;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Size 0 Rhombus (just the cell itself)
                sums.insert(grid[i][j]);

                // Try expanding to sizes L = 1, 2, ...
                for (int L = 1; ; ++L) {
                    // Check if the four corners are within bounds
                    int topR = i, topC = j;
                    int rightR = i + L, rightC = j + L;
                    int leftR = i + L, leftC = j - L;
                    int bottomR = i + 2 * L, bottomC = j;

                    if (bottomR >= m || rightC >= n || leftC < 0) break;

                    int currentSum = 0;
                    // Traverse 4 edges: 
                    // Top corner to Right, Right to Bottom, Bottom to Left, Left to Top
                    for (int k = 0; k < L; ++k) {
                        currentSum += grid[topR + k][topC + k];       // Top -> Right
                        currentSum += grid[rightR + k][rightC - k];   // Right -> Bottom
                        currentSum += grid[bottomR - k][bottomC - k]; // Bottom -> Left
                        currentSum += grid[leftR - k][leftC + k];     // Left -> Top
                    }
                    sums.insert(currentSum);
                }
                
                while (sums.size() > 3) {
                    sums.erase(sums.begin());
                }
            }
        }

        vector<int> result(sums.rbegin(), sums.rend());
        return result;
    }
};