class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, ' ');
        char currentChar = 'a';
        
        // Step 1: Greedily construct the candidate string
        for (int i = 0; i < n; i++) {
            if (word[i] == ' ') {
                // If we run out of lowercase English letters, a valid string is impossible
                if (currentChar > 'z') return ""; 
                
                // Assign the same character to all indices j where lcp[i][j] > 0
                for (int j = i; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        word[j] = currentChar;
                    }
                }
                currentChar++; // Move to the next available character for future unassigned cells
            }
        }
        
        // Step 2: Validate the constructed string against the given LCP matrix
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int expectedLCP = 0;
                
                // If the characters match, calculate the expected LCP using DP
                if (word[i] == word[j]) {
                    expectedLCP = (i + 1 < n && j + 1 < n) ? lcp[i + 1][j + 1] + 1 : 1;
                }
                
                // If the given matrix doesn't match the mathematical reality, it's invalid
                if (lcp[i][j] != expectedLCP) {
                    return "";
                }
            }
        }
        
        return word;
    }
};