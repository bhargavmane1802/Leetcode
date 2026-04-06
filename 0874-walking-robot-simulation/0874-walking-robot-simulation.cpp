struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
class Solution {
public:

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, PairHash> obs_set;
        for (const auto& obs : obstacles) {
            obs_set.insert({obs[0], obs[1]});
        }
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        int x = 0, y = 0;
        int dir = 0;     
        int max_dist_sq = 0;
        
        for (int cmd : commands) {
            if (cmd == -2) {
                
                dir = (dir + 3) % 4;
            } else if (cmd == -1) {
                dir = (dir + 1) % 4;
            } else {
                for (int i = 0; i < cmd; ++i) {
                    int next_x = x + dx[dir];
                    int next_y = y + dy[dir];
                    if (obs_set.count({next_x, next_y})) {
                        break;
                    }
                    x = next_x;
                    y = next_y;                    
                    max_dist_sq = max(max_dist_sq, x * x + y * y);
                }
            }
        }
        return max_dist_sq;
    }
};