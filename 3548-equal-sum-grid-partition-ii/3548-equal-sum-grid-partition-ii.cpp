class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long totalSum = 0;
        // Frequency of each value in the entire grid
        vector<int> totalFreq(100001, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                totalSum += grid[i][j];
                if (grid[i][j] <= 100000) totalFreq[grid[i][j]]++;
            }
        }

        // --- Horizontal Cuts ---
        long long s1 = 0;
        vector<int> f1(100001, 0); // Frequency of values in the top section
        if (m > 1) {
            for (int i = 0; i < m - 1; ++i) {
                for (int j = 0; j < n; ++j) {
                    s1 += grid[i][j];
                    if (grid[i][j] <= 100000) f1[grid[i][j]]++;
                }
                long long s2 = totalSum - s1;
                if (s1 == s2) return true;

                // Case: Discount from Top Section (S1)
                if (s1 > s2) {
                    long long diff = s1 - s2;
                    if (diff <= 100000) {
                        int h1 = i + 1; // Height of S1
                        if (h1 > 1 && n > 1) { // It's a 2D block
                            if (f1[diff] > 0) return true;
                        } else { // It's a single line
                            if (h1 == 1) { // Row line
                                if (grid[0][0] == (int)diff || grid[0][n - 1] == (int)diff) return true;
                            } else { // Column line (n == 1)
                                if (grid[0][0] == (int)diff || grid[i][0] == (int)diff) return true;
                            }
                        }
                    }
                } 
                // Case: Discount from Bottom Section (S2)
                else {
                    long long diff = s2 - s1;
                    if (diff <= 100000) {
                        int h2 = m - (i + 1); // Height of S2
                        if (h2 > 1 && n > 1) { // It's a 2D block
                            if (totalFreq[diff] - f1[diff] > 0) return true;
                        } else { // It's a single line
                            if (h2 == 1) { // Row line
                                if (grid[m - 1][0] == (int)diff || grid[m - 1][n - 1] == (int)diff) return true;
                            } else { // Column line (n == 1)
                                if (grid[i + 1][0] == (int)diff || grid[m - 1][0] == (int)diff) return true;
                            }
                        }
                    }
                }
            }
        }

        // --- Vertical Cuts ---
        if (n > 1) {
            s1 = 0;
            fill(f1.begin(), f1.end(), 0);
            for (int j = 0; j < n - 1; ++j) {
                for (int i = 0; i < m; ++i) {
                    s1 += grid[i][j];
                    if (grid[i][j] <= 100000) f1[grid[i][j]]++;
                }
                long long s2 = totalSum - s1;
                if (s1 == s2) return true;

                // Case: Discount from Left Section (S1)
                if (s1 > s2) {
                    long long diff = s1 - s2;
                    if (diff <= 100000) {
                        int w1 = j + 1; // Width of S1
                        if (m > 1 && w1 > 1) { // 2D Block
                            if (f1[diff] > 0) return true;
                        } else { // Single Line
                            if (w1 == 1) { // Column line
                                if (grid[0][0] == (int)diff || grid[m - 1][0] == (int)diff) return true;
                            } else { // Row line (m == 1)
                                if (grid[0][0] == (int)diff || grid[0][j] == (int)diff) return true;
                            }
                        }
                    }
                } 
                // Case: Discount from Right Section (S2)
                else {
                    long long diff = s2 - s1;
                    if (diff <= 100000) {
                        int w2 = n - (j + 1); // Width of S2
                        if (m > 1 && w2 > 1) { // 2D Block
                            if (totalFreq[diff] - f1[diff] > 0) return true;
                        } else { // Single Line
                            if (w2 == 1) { // Column line
                                if (grid[0][n - 1] == (int)diff || grid[m - 1][n - 1] == (int)diff) return true;
                            } else { // Row line (m == 1)
                                if (grid[0][j + 1] == (int)diff || grid[0][n - 1] == (int)diff) return true;
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
};