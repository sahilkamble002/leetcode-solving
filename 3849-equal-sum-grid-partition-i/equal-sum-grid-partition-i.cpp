class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
       if (grid.empty() || grid[0].empty()) return false;

    int m = grid.size();
    int n = grid[0].size();

    // Use long long to avoid overflow
    long long total = 0;

    // Calculate total sum
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            total += grid[i][j];
        }
    }

    // If total is odd → cannot split
    if (total % 2 != 0) return false;

    long long target = total / 2;

    // 🔹 Horizontal cuts
    long long curr = 0;
    for (int i = 0; i < m - 1; i++) {
        long long rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += grid[i][j];
        }
        curr += rowSum;

        if (curr == target) return true;
    }

    // 🔹 Vertical cuts
    curr = 0;
    for (int j = 0; j < n - 1; j++) {
        long long colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += grid[i][j];
        }
        curr += colSum;

        if (curr == target) return true;
    }

    return false;
   
    }
};