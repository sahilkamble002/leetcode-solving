class Solution {
public:    int m, n;
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& vis) {
        vis[r][c] = true;
        
        for (auto &d : directions) {
            int nr = r + d[0];
            int nc = c + d[1];
            
            if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                !vis[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {
                
                dfs(nr, nc, heights, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
                m = heights.size();
        n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        // Pacific (top + left)
        for (int i = 0; i < m; i++) dfs(i, 0, heights, pacific);
        for (int j = 0; j < n; j++) dfs(0, j, heights, pacific);
        
        // Atlantic (bottom + right)
        for (int i = 0; i < m; i++) dfs(i, n-1, heights, atlantic);
        for (int j = 0; j < n; j++) dfs(m-1, j, heights, atlantic);
        
        vector<vector<int>> result;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
};