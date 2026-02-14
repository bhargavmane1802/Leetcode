class Solution {
public:
    string removeKdigits(string num, int k) {
        string s = "";
        for (char c : num) {
            while (s.length() > 0 && s.back() > c && k > 0) {
                s.pop_back();
                k--;
            }
            s.push_back(c);
        }
        while (k > 0 && !s.empty()) {
            s.pop_back();
            k--;
        }
        int i = 0;
        while (i < s.size() && s[i] == '0') {
            i++;
        }
        return (i == s.size()) ? "0" : s.substr(i);
    }
};