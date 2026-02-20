class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0;
        int i = 0;
        vector<string> substrings;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '1') count++;
            else count--;
            
            if (count == 0) {
                string inner = s.substr(i + 1, j - i - 1);                
                substrings.push_back("1" + makeLargestSpecial(inner) + "0");
                i = j + 1;
            }
        }
        
        sort(substrings.rbegin(), substrings.rend());
        
        string result = "";
        for (const string& str : substrings) {
            result += str;
        }
        
        return result;
        
    }
};