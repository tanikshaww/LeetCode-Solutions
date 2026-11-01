class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        if(n % 2 == 1){
            sum += nums[n - 1];
            n--;
        }
        for(int i = 0; i < n - 1; i+=2){
            int x = nums[i];
            int y = nums[i + 1];

            sum = sum + (x - y);
        }

        return sum;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna