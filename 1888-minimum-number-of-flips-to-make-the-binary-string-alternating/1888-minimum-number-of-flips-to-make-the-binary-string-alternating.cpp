class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string doubled = s + s;
        
        // Two target alternating patterns
        string target1 = "", target2 = "";
        for (int i = 0; i < doubled.size(); i++) {
            target1 += (i % 2 == 0 ? '0' : '1');
            target2 += (i % 2 == 0 ? '1' : '0');
        }

        int diff1 = 0, diff2 = 0;
        int ans = doubled.size();
        for (int i = 0; i < doubled.size(); i++) {
            if (doubled[i] != target1[i]) diff1++;
            if (doubled[i] != target2[i]) diff2++;
            if (i >= n) {
                if (doubled[i - n] != target1[i - n]) diff1--;
                if (doubled[i - n] != target2[i - n]) diff2--;
            }
            if (i >= n - 1) {
                ans = min({ans, diff1, diff2});
            }
        }

        return ans;
    }
};