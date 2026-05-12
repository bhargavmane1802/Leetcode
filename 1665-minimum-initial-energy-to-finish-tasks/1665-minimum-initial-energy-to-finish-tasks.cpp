class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Your correct sorting logic!
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b){
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        
        int ans = 0; // Total initial energy required
        int current_energy = 0; // Energy we have at the moment
        
        for(int i = 0; i < tasks.size(); i++){
            // If we don't have enough energy for the minimum threshold, top it up
            if (current_energy < tasks[i][1]) {
                ans += (tasks[i][1] - current_energy);
                current_energy = tasks[i][1]; // We now have exactly the minimum needed
            }
            // Subtract the actual energy spent on the task
            current_energy -= tasks[i][0];
        }
        
        return ans;
    }
};