class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // For each street type, define which directions it connects to
        // Directions: 0=left, 1=right, 2=up, 3=down
        vector<vector<int>> connects = {
            {},           // placeholder for index 0
            {0, 1},       // 1: left, right
            {2, 3},       // 2: up, down
            {0, 3},       // 3: left, down
            {1, 3},       // 4: right, down
            {0, 2},       // 5: left, up
            {1, 2}        // 6: right, up
        };
        
        // Direction vectors: left, right, up, down
        vector<int> dr = {0, 0, -1, 1};
        vector<int> dc = {-1, 1, 0, 0};
        
        // Opposite direction: left<->right, up<->down
        vector<int> opposite = {1, 0, 3, 2};
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == m - 1 && c == n - 1) return true;
            
            int street = grid[r][c];
            
            // Try each direction the current street connects to
            for (int dir : connects[street]) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];
                
                // Check bounds
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (visited[nr][nc]) continue;
                
                // Check if neighbor street connects back to current cell
                int neighborStreet = grid[nr][nc];
                bool canConnect = false;
                for (int ndir : connects[neighborStreet]) {
                    if (ndir == opposite[dir]) {
                        canConnect = true;
                        break;
                    }
                }
                
                if (canConnect) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        
        return false;
    }
};