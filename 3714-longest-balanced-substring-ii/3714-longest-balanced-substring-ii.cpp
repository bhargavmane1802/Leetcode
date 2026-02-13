class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0);
            int distinct_count = 0;
            int max_freq = 0;
            for (int j = i; j < n; ++j) {
                int char_idx = s[j] - 'a';
                if (freq[char_idx] == 0) {
                    distinct_count++;
                }
                
                freq[char_idx]++;
                max_freq = max(max_freq, freq[char_idx]);
                int current_len = j - i + 1;
                if (max_freq * distinct_count == current_len) {
                    max_len = max(max_len, current_len);
                }
            }
        }
        return max_len;
    }
};