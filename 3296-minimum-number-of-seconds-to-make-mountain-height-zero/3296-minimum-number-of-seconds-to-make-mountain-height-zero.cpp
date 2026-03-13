class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 0;
        long long high = 1e16; 
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (canReduce(mountainHeight, workerTimes, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return ans;
    }

private:
    bool canReduce(int targetHeight, const vector<int>& workerTimes, long long timeLimit) {
        long long totalHeightReduced = 0;
        
        for (int w : workerTimes) {
            double val = (8.0 * timeLimit) / w;
            long long x = (-1.0 + sqrt(1.0 + val)) / 2.0;
            
            totalHeightReduced += x;
            if (totalHeightReduced >= targetHeight) return true;
        }
        
        return totalHeightReduced >= targetHeight;
    }
};