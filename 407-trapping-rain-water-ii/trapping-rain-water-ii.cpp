class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        
        // Edge case: no interior cells possible
        if (m < 3 || n < 3) return 0;
        
        // Min-heap: {height, row, col}
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // ── Step 1: Push all boundary cells ───────────────────
        for (int i = 0; i < m; i++) {
            for (int j : {0, n-1}) {
                minHeap.push({heightMap[i][j], i, j});
                visited[i][j] = true;
            }
        }
        for (int j = 1; j < n-1; j++) {
            for (int i : {0, m-1}) {
                minHeap.push({heightMap[i][j], i, j});
                visited[i][j] = true;
            }
        }
        
        // ── Step 2: BFS inward from lowest boundary ───────────
        int water = 0;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        while (!minHeap.empty()) {
            auto [waterLevel, r, c] = minHeap.top();
            minHeap.pop();
            
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d];
                int nc = c + dy[d];
                
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (visited[nr][nc]) continue;
                
                visited[nr][nc] = true;
                
                // Water trapped at this neighbor
                water += max(0, waterLevel - heightMap[nr][nc]);
                
                // This neighbor's effective "wall height" for further BFS
                minHeap.push({max(waterLevel, heightMap[nr][nc]), nr, nc});
            }
        }
        
        return water;
    }
};