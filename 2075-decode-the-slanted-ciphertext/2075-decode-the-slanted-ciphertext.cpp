class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        if (n == 0) return ""; 
        
        int cols = n / rows;
        string originalText = "";
        
        for (int c = 0; c < cols; ++c) {
            for (int r = 0; r < rows && r + c < cols; ++r) {
                int index = r * cols + (c + r);
                originalText += encodedText[index];
            }
        }
        while (!originalText.empty() && originalText.back() == ' ') {
            originalText.pop_back();
        }
        
        return originalText;
    }
};