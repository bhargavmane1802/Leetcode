class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
       int n = nums.size();
        if (n < 4) return 0; // Constraint says n >= 4, but good practice

        // Use a very small number for invalid states
        const long long INF = 1e18; 
        
        // 1. Prefix Sums
        // S[i] will store sum of nums[0...i]
        vector<long long> S(n);
        S[0] = nums[0];
        for (int i = 1; i < n; i++) {
            S[i] = S[i - 1] + nums[i];
        }
        
        // 2. Compute L[i]: Max strictly increasing subarray sum ending at i (len >= 2)
        vector<long long> L(n, -INF);
        // Temporary DP array to track increasing sum ending at i regardless of length
        vector<long long> dp_inc(n); 
        
        dp_inc[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                // We can extend the previous sequence
                dp_inc[i] = dp_inc[i - 1] + nums[i];
                // L[i] is valid only if length >= 2. 
                // Either extend a valid L[i-1] or just take the pair (i-1, i)
                // However, dp_inc[i-1] + nums[i] covers both cases correctly 
                // because dp_inc tracks the max continuous sum ending there.
                L[i] = dp_inc[i];
            } else {
                dp_inc[i] = nums[i]; // Reset: sequence starts fresh here
                L[i] = -INF;         // Cannot end a strictly increasing subarray (len>=2) here
            }
        }
        
        // 3. Compute R[i]: Max strictly increasing subarray sum starting at i (len >= 2)
        vector<long long> R(n, -INF);
        vector<long long> dp_dec_start(n); // Increasing suffix sum starting at i
        
        dp_dec_start[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                dp_dec_start[i] = nums[i] + dp_dec_start[i + 1];
                R[i] = dp_dec_start[i];
            } else {
                dp_dec_start[i] = nums[i];
                R[i] = -INF;
            }
        }
        
        // 4. Find Max Trionic Sum
        // Iterate q from 2 to n-2 (since q needs p (>=1) before it and r (>=q+1) after it)
        long long max_sum = -INF;
        long long current_max_p_term = -INF;
        
        for (int q = 2; q < n - 1; q++) {
            // We are looking for a strictly decreasing segment ending at q.
            // This means nums[q] < nums[q-1].
            
            if (nums[q] < nums[q - 1]) {
                // If this is the start of a new decreasing run (i.e., previous pair wasn't decreasing)
                // Reset the max_p_term tracker.
                if (nums[q - 1] >= nums[q - 2]) {
                    current_max_p_term = -INF;
                }
                
                // Potential p is q-1
                int p = q - 1;
                if (L[p] != -INF) {
                    long long p_term = L[p] - S[p];
                    current_max_p_term = max(current_max_p_term, p_term);
                }
                
                // If we have a valid p and a valid R[q], calculate total
                if (current_max_p_term != -INF && R[q] != -INF) {
                    long long q_term = R[q] + S[q - 1];
                    max_sum = max(max_sum, current_max_p_term + q_term);
                }
            } else {
                // Sequence is not decreasing, reset
                current_max_p_term = -INF;
            }
        }
        
        return max_sum;
    }
};