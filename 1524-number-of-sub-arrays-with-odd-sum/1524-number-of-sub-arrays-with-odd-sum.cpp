class Solution {
public:
    int numOfSubarrays(std::vector<int>& arr) {
        long long odd_count = 0;
        long long even_count = 1;
        long long current_sum = 0;
        long long total_odd_subarrays = 0;
        const int MOD = 1e9 + 7;

        for (int num : arr) {
           current_sum += num;

           if (current_sum % 2 != 0) {
            total_odd_subarrays = (total_odd_subarrays + even_count) % MOD;
            odd_count++;
           } else {
            total_odd_subarrays = (total_odd_subarrays + odd_count) % MOD;
            even_count++;
           }
        }
        
        return total_odd_subarrays;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna