class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        int rowLen = m - k + 1;
        int colLen = n - k + 1;
        vector<vector<int>> ans(rowLen, vector<int>(colLen));

        for (int i = 0; i < rowLen; ++i) {
            for (int j = 0; j < colLen; ++j) {
                set<int> distinctValues;
                for (int r = i; r < i + k; ++r) {
                    for (int c = j; c < j + k; ++c) {
                        distinctValues.insert(grid[r][c]);
                    }
                }

                if (distinctValues.size() <= 1) {
                    ans[i][j] = 0;
                } else {
                    int minDiff = INT_MAX;
                    auto it = distinctValues.begin();
                    int prev = *it;
                    ++it;
                    
                    while (it != distinctValues.end()) {
                        minDiff = min(minDiff, *it - prev);
                        prev = *it;
                        ++it;
                    }
                    ans[i][j] = minDiff;
                }
            }
        }

        return ans;
    }
};