class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;
        std::deque<int> dq; // stores indices in non-increasing order of nums
        int j = n - 1;

        for (int i = n - 1; i >= 0; --i) {
            // Maintain monotonic deque: remove elements smaller than nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                int l = dq.back();
                dq.pop_back();
                int r = dq.empty() ? j + 1 : dq.back();
                cost += (long long)(r - l) * (nums[i] - nums[l]);
            }
            dq.push_back(i);

            // If cost exceeds k, shrink the window from the right (j)
            while (cost > k) {
                cost -= nums[dq.front()] - nums[j];
                if (dq.front() == j) {
                    dq.pop_front();
                }
                j--;
            }

            // All subarrays starting at 'i' and ending anywhere from 'i' to 'j' are valid
            ans += (j - i + 1);
        }

        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna