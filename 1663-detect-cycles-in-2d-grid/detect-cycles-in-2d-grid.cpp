class Solution {
public:
int m, n;
    vector<vector<bool>> visited;
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool dfs(vector<vector<char>>& grid, int row, int col, int prevRow, int prevCol) {
        visited[row][col] = true;
        
        for (auto& dir : dirs) {
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            
            // Skip out of bounds
            if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n)
                continue;
            
            // Skip different characters
            if (grid[newRow][newCol] != grid[row][col])
                continue;
            
            // Skip the cell we just came from (immediate parent)
            if (newRow == prevRow && newCol == prevCol)
                continue;
            
            // If already visited → cycle found!
            if (visited[newRow][newCol])
                return true;
            
            if (dfs(grid, newRow, newCol, row, col))
                return true;
        }
        
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    // Start DFS from each unvisited cell
                    // -1, -1 means no parent
                    if (dfs(grid, i, j, -1, -1))
                        return true;
                }
            }
        }
        
        return false;
    }
};