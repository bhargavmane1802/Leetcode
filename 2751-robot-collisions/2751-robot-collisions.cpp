class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        // Create an array of original indices to track them after sorting
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        
        // Sort indices based on the robots' starting positions (Left to Right)
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return positions[i] < positions[j];
        });
        
        vector<int> stack; // Stack to hold the indices of surviving robots
        
        for (int i : indices) {
            if (directions[i] == 'R') {
                // Moving right, push to stack to potentially collide with future 'L' robots
                stack.push_back(i);
            } else {
                // Moving left, resolve collisions with any 'R' robots on the stack
                bool survived = true;
                
                while (!stack.empty() && directions[stack.back()] == 'R') {
                    int top_i = stack.back();
                    
                    if (healths[i] > healths[top_i]) {
                        // Current 'L' robot wins, top 'R' robot is destroyed
                        stack.pop_back();
                        healths[i] -= 1;
                        healths[top_i] = 0; 
                    } else if (healths[i] < healths[top_i]) {
                        // Top 'R' robot wins, current 'L' robot is destroyed
                        healths[top_i] -= 1;
                        healths[i] = 0;
                        survived = false;
                        break; // Stop checking, 'L' robot is dead
                    } else {
                        // Both have the same health, both are destroyed
                        stack.pop_back();
                        healths[i] = 0;
                        healths[top_i] = 0;
                        survived = false;
                        break; // Stop checking, 'L' robot is dead
                    }
                }
                
                // If the 'L' robot survived all collisions, it goes on the stack
                if (survived) {
                    stack.push_back(i);
                }
            }
        }
        
        // The stack now contains the indices of all surviving robots.
        // We must return their healths in the order they originally appeared in the input.
        sort(stack.begin(), stack.end());
        
        vector<int> result;
        for (int i : stack) {
            result.push_back(healths[i]);
        }
        
        return result;
        
    }
};