class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> countEven(26, 0);
        vector<int> countOdd(26, 0);
        
        int n = s1.length();
        
        // Count frequencies for s1 (add) and s2 (subtract) in a single pass
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                countEven[s1[i] - 'a']++;
                countEven[s2[i] - 'a']--;
            } else {
                countOdd[s1[i] - 'a']++;
                countOdd[s2[i] - 'a']--;
            }
        }
        
        // Check if all counts balanced out to exactly zero
        for (int i = 0; i < 26; i++) {
            if (countEven[i] != 0 || countOdd[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};