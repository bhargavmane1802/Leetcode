class Solution {
public:
    vector<string> readBinaryWatch(int t) {
        vector<string> result;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                    if (__builtin_popcount(h) + __builtin_popcount(m) == t) {
                    string time = to_string(h) + ":";
                    if (m < 10) time += "0";
                    
                    time += to_string(m);
                    result.push_back(time);
                }
            }
        }
        return result;
    }
};