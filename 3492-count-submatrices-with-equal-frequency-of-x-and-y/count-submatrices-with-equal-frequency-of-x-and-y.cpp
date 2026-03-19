class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
         int m = grid.size(), n = grid[0].size();
            vector<vector<int>> px(m, vector<int>(n, 0));
    vector<vector<int>> py(m, vector<int>(n, 0));

    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            // build prefix for X
            px[i][j] = (grid[i][j] == 'X');
            if (i > 0) px[i][j] += px[i - 1][j];
            if (j > 0) px[i][j] += px[i][j - 1];
            if (i > 0 && j > 0) px[i][j] -= px[i - 1][j - 1];

            // build prefix for Y
            py[i][j] = (grid[i][j] == 'Y');
            if (i > 0) py[i][j] += py[i - 1][j];
            if (j > 0) py[i][j] += py[i][j - 1];
            if (i > 0 && j > 0) py[i][j] -= py[i - 1][j - 1];

            int x = px[i][j];
            int y = py[i][j];

            if (x == y && x > 0) count++;
        }
    }

    return count;
    }
};