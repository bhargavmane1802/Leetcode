class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int N = n + m - 1;
        
        // Initialize the result string with '?'
        string ans(N, '?');
        
        // Step 1: Apply 'T' constraints
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int k = 0; k < m; k++) {
                    // If a character is already set by another 'T' and conflicts, it's impossible
                    if (ans[i + k] != '?' && ans[i + k] != str2[k]) {
                        return "";
                    }
                    ans[i + k] = str2[k];
                }
            }
        }
        
        // Step 2: Track the last '?' for each 'F' constraint
        // check_F[i] stores all 'F' constraints (their starting indices) whose LAST '?' is at index i
        vector<vector<int>> check_F(N);
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                int last_q = -1;
                for (int k = 0; k < m; k++) {
                    if (ans[i + k] == '?') {
                        last_q = i + k;
                    }
                }
                
                if (last_q == -1) {
                    // The window is fully fixed by 'T' constraints. Check if it accidentally matches str2.
                    bool match = true;
                    for (int k = 0; k < m; k++) {
                        if (ans[i + k] != str2[k]) {
                            match = false;
                            break;
                        }
                    }
                    if (match) return ""; // Inherent contradiction
                } else {
                    check_F[last_q].push_back(i);
                }
            }
        }
        
        // Step 3: Greedily fill remaining '?' from left to right
        for (int i = 0; i < N; i++) {
            if (ans[i] == '?') {
                bool banned[26] = {false};
                
                // Check all 'F' constraints that rely on this index as their LAST chance to avoid a match
                for (int j : check_F[i]) {
                    bool almost_match = true;
                    
                    // Verify if the rest of the window perfectly matches str2
                    for (int k = 0; k < m; k++) {
                        if (j + k == i) continue; // Skip the current '?' index
                        if (ans[j + k] != str2[k]) {
                            almost_match = false;
                            break;
                        }
                    }
                    
                    // If everything else matches, we MUST NOT pick the character that completes str2
                    if (almost_match) {
                        banned[str2[i - j] - 'a'] = true;
                    }
                }
                
                // Pick the lexicographically smallest non-banned character
                char picked = '?';
                for (char c = 'a'; c <= 'z'; c++) {
                    if (!banned[c - 'a']) {
                        picked = c;
                        break;
                    }
                }
                
                // If all 26 characters are banned (an extremely rare overlap), a valid string is impossible
                if (picked == '?') return ""; 
                
                ans[i] = picked;
            }
        }
        
        return ans;
    }
};