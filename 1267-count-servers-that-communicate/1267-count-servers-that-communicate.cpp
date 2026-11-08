class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        std::vector<int> rowCount(m, 0);
        std::vector<int> colCount(n, 0);
        
        // First pass: count servers in each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        int communicatingServers = 0;
        
        // Second pass: check which servers can communicate
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (rowCount[i] > 1 || colCount[j] > 1) {
                        communicatingServers++;
                    }
                }
            }
        }
        
        return communicatingServers;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna