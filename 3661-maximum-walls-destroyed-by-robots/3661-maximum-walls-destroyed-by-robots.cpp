class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        
        // Pair each robot's position with its distance and sort them left-to-right
        vector<pair<int, int>> R(n);
        for (int i = 0; i < n; ++i) {
            R[i] = {robots[i], distance[i]};
        }
        sort(R.begin(), R.end());
        sort(walls.begin(), walls.end());

        // Helper lambda to count the number of walls in a strictly closed interval [L, R]
        auto count_walls = [&](int L, int R_val) -> int {
            if (L > R_val) return 0; // Invalid or empty interval
            auto it1 = lower_bound(walls.begin(), walls.end(), L);
            auto it2 = upper_bound(walls.begin(), walls.end(), R_val);
            return std::distance(it1, it2);
        };

        // Any wall sharing the exact same coordinate as a robot is guaranteed to be 
        // destroyed, regardless of which direction the robot decides to shoot.
        int base_walls = 0;
        for (int i = 0; i < n; ++i) {
            if (binary_search(walls.begin(), walls.end(), R[i].first)) {
                base_walls++;
            }
        }

        // dp0 represents the max walls destroyed ending with the current robot shooting LEFT
        // dp1 represents the max walls destroyed ending with the current robot shooting RIGHT
        int dp0 = count_walls(R[0].first - R[0].second, R[0].first - 1);
        int dp1 = 0;

        for (int i = 1; i < n; ++i) {
            int P_prev = R[i-1].first;
            int D_prev = R[i-1].second;
            int P_curr = R[i].first;
            int D_curr = R[i].second;

            // Interval for Previous Robot shooting RIGHT (stops at current robot)
            int IR_L = P_prev + 1;
            int IR_R = min(P_prev + D_prev, P_curr - 1);

            // Interval for Current Robot shooting LEFT (stops at previous robot)
            int IL_L = max(P_curr - D_curr, P_prev + 1);
            int IL_R = P_curr - 1;

            int c00 = 0;                                 // Neither shoots into the segment
            int c10 = count_walls(IR_L, IR_R);           // Only previous robot shoots RIGHT
            int c01 = count_walls(IL_L, IL_R);           // Only current robot shoots LEFT
            
            // If both shoot into the segment, we must use the inclusion-exclusion principle 
            // to avoid double-counting walls that fall into the overlapping crossfire
            int overlap_L = max(IR_L, IL_L);
            int overlap_R = min(IR_R, IL_R);
            int overlap_count = count_walls(overlap_L, overlap_R);
            int c11 = c10 + c01 - overlap_count;

            // DP Transitions
            int next_dp0 = max(dp0 + c01, dp1 + c11);
            int next_dp1 = max(dp0 + c00, dp1 + c10);

            dp0 = next_dp0;
            dp1 = next_dp1;
        }

        // Add the coverage of the last robot shooting RIGHT (unblocked to infinity)
        int R_last_right = count_walls(R[n-1].first + 1, R[n-1].first + R[n-1].second);
        
        return max(dp0, dp1 + R_last_right) + base_walls;
    }
};