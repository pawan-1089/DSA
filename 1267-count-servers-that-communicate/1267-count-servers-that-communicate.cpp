class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Vectors to track the number of servers in each row and column
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        // Step 1: Count total servers in each row and column
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    rowCount[r]++;
                    colCount[c]++;
                }
            }
        }
        
        int communicableServers = 0;
        
        // Step 2: Identify servers that share a row or column with another server
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    // If row or column count is greater than 1, this server can communicate
                    if (rowCount[r] > 1 || colCount[c] > 1) {
                        communicableServers++;
                    }
                }
            }
        }
        
        return communicableServers;
    }
};
