class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;
        
        for (int layer = 0; layer < layers; layer++) {
            // Extract layer elements in counter-clockwise order
            vector<int> elements;
            int top = layer, bottom = m - 1 - layer;
            int left = layer, right = n - 1 - layer;
            
            // Top row: left to right
            for (int col = left; col <= right; col++)
                elements.push_back(grid[top][col]);
            // Right col: top+1 to bottom
            for (int row = top + 1; row <= bottom; row++)
                elements.push_back(grid[row][right]);
            // Bottom row: right-1 to left
            for (int col = right - 1; col >= left; col--)
                elements.push_back(grid[bottom][col]);
            // Left col: bottom-1 to top+1
            for (int row = bottom - 1; row >= top + 1; row--)
                elements.push_back(grid[row][left]);
            
            // Rotate by k positions (counter-clockwise = shift left by k)
            int sz = elements.size();
            int shift = k % sz;
            rotate(elements.begin(), elements.begin() + shift, elements.end());
            
            // Put elements back
            int idx = 0;
            for (int col = left; col <= right; col++)
                grid[top][col] = elements[idx++];
            for (int row = top + 1; row <= bottom; row++)
                grid[row][right] = elements[idx++];
            for (int col = right - 1; col >= left; col--)
                grid[bottom][col] = elements[idx++];
            for (int row = bottom - 1; row >= top + 1; row--)
                grid[row][left] = elements[idx++];
        }
        
        return grid;
    }
};