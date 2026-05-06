class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        
        // Step 1: Apply gravity - stones fall to the right in each row
        for (int i = 0; i < m; i++) {
            int emptyPos = n - 1; // Next position a stone can fall to
            
            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    // Obstacle: reset empty position to just left of it
                    emptyPos = j - 1;
                } else if (boxGrid[i][j] == '#') {
                    // Stone: move it to emptyPos
                    boxGrid[i][j] = '.';
                    boxGrid[i][emptyPos] = '#';
                    emptyPos--;
                }
                // '.' : do nothing, emptyPos stays
            }
        }
        
        // Step 2: Rotate 90 degrees clockwise
        // [i][j] -> [j][m - 1 - i]  (result is n x m)
        vector<vector<char>> result(n, vector<char>(m));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][m - 1 - i] = boxGrid[i][j];
            }
        }
        
        return result;
    }
};