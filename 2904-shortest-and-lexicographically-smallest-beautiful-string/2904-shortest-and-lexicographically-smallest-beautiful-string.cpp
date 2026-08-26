class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1')
                temp.push_back(i);
        }

        if (temp.size() < k)
            return "";

        int t = INT_MAX;
        int ansIndex = 0;

        for (int i = 0; i + k - 1 < temp.size(); i++) {

            int len = temp[i + k - 1] - temp[i] + 1;

            if (len < t) {
                t = len;
                ansIndex = i;
            }

            else if (len == t) {

                int a = i + 1;
                int b = ansIndex + 1;

                while (a <= i + k - 1 &&
                       temp[a] - temp[a - 1] ==
                       temp[b] - temp[b - 1]) {
                    a++;
                    b++;
                }

                if (a <= i + k - 1 &&
                    temp[a] - temp[a - 1] >
                    temp[b] - temp[b - 1]) {
                    ansIndex = i;
                }
            }
        }

        return s.substr(temp[ansIndex], t);
    }
};