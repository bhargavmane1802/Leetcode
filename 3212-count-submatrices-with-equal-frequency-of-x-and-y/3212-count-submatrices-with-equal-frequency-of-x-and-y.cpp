class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
       int R = grid.size();
        int C = grid[0].size();
        
        // 2D arrays to store prefix counts of 'X' and 'Y'
        // Using R+1 and C+1 to handle boundary conditions (i-1, j-1) easily
        vector<vector<int>> prefX(R + 1, vector<int>(C + 1, 0));
        vector<vector<int>> prefY(R + 1, vector<int>(C + 1, 0));
        
        int validSubmatrices = 0;
        
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                // Standard 2D prefix sum formula:
                // Current = (current_val) + Top + Left - TopLeft
                prefX[i + 1][j + 1] = (grid[i][j] == 'X' ? 1 : 0) 
                                    + prefX[i][j + 1] + prefX[i + 1][j] - prefX[i][j];
                
                prefY[i + 1][j + 1] = (grid[i][j] == 'Y' ? 1 : 0) 
                                    + prefY[i][j + 1] + prefY[i + 1][j] - prefY[i][j];
                
                // Condition 1: Equal frequency of 'X' and 'Y'
                // Condition 2: At least one 'X'
                if (prefX[i + 1][j + 1] == prefY[i + 1][j + 1] && prefX[i + 1][j + 1] > 0) {
                    validSubmatrices++;
                }
            }
        }
        
        return validSubmatrices;
    }
};