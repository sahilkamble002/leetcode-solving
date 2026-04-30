class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
     int m = grid.size(), n = grid[0].size();
        
        // Max meaningful cost: at most (m+n-1) cells on any path,
        // each costing at most 1, so cap at min(k, m+n-2)
        int maxCost = min(k, m + n - 2);
        
        // dp[i][j][c] = max score at (i,j) with total cost c
        // -1 means this state is unreachable
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(maxCost + 1, -1))
        );
        
        // Starting cell: grid[0][0] == 0 (guaranteed), score=0, cost=0
        dp[0][0][0] = 0;
        
        auto cellScore = [&](int i, int j) { return grid[i][j]; };
        auto cellCost  = [&](int i, int j) { return grid[i][j] > 0 ? 1 : 0; };
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= maxCost; c++) {
                    if (dp[i][j][c] == -1) continue; // unreachable state
                    
                    int curScore = dp[i][j][c];
                    
                    // Try moving right: (i, j+1)
                    if (j + 1 < n) {
                        int nc = c + cellCost(i, j + 1);
                        int ns = curScore + cellScore(i, j + 1);
                        if (nc <= maxCost) {
                            dp[i][j+1][nc] = max(dp[i][j+1][nc], ns);
                        }
                    }
                    
                    // Try moving down: (i+1, j)
                    if (i + 1 < m) {
                        int nc = c + cellCost(i + 1, j);
                        int ns = curScore + cellScore(i + 1, j);
                        if (nc <= maxCost) {
                            dp[i+1][j][nc] = max(dp[i+1][j][nc], ns);
                        }
                    }
                }
            }
        }
        
        // Find the best score at destination with any cost <= k
        int ans = -1;
        for (int c = 0; c <= maxCost; c++) {
            if (dp[m-1][n-1][c] != -1) {
                ans = max(ans, dp[m-1][n-1][c]);
            }
        }
        return ans;   
    }
};