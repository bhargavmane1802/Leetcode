#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
    int memo[301][27]; // word index, position of the "other" finger

    // Helper to calculate Manhattan distance
    int getDist(int from, int to) {
        if (from == 26) return 0; // Finger was free
        int x1 = from / 6, y1 = from % 6;
        int x2 = to / 6, y2 = to % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string& word, int idx, int otherFinger) {
        if (idx == word.length()) return 0;
        if (memo[idx][otherFinger] != -1) return memo[idx][otherFinger];

        int currChar = word[idx] - 'A';
        int prevChar = word[idx - 1] - 'A';

        // Option 1: Move the finger that typed the previous character
        int moveSame = getDist(prevChar, currChar) + solve(word, idx + 1, otherFinger);

        // Option 2: Move the "other" finger
        int moveOther = getDist(otherFinger, currChar) + solve(word, idx + 1, prevChar);

        return memo[idx][otherFinger] = min(moveSame, moveOther);
    }

public:
    int minimumDistance(string word) {
        // Initialize memo with -1
        for (int i = 0; i <= word.length(); ++i) {
            for (int j = 0; j < 27; ++j) memo[i][j] = -1;
        }

        // Start at index 1 because the first finger moves to word[0] for free.
        // Finger 1 is at word[0], Finger 2 is at "26" (free).
        return solve(word, 1, 26);
    }
};