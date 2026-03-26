class Solution {
public:
    bool check(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();

        // cnt1 = value counts in top section
        // cnt2 = value counts in bottom section (starts with all cells)
        unordered_map<long long, int> cnt1, cnt2;
        long long s1 = 0, s2 = 0;

        for (int i = 0; i < m; i++)
            for (int x : g[i]) { s2 += x; cnt2[x]++; }

        for (int i = 0; i < m - 1; i++) {
            // Move row i from bottom to top
            for (int x : g[i]) {
                s1 += x; s2 -= x;
                cnt1[x]++; cnt2[x]--;
                if (cnt2[x] == 0) cnt2.erase(x);
            }

            if (s1 == s2) return true;

            // Try discounting one cell to balance
            long long diff;
            unordered_map<long long, int>* sectionCnt;
            int sectionRows;

            if (s1 > s2) {
                diff = s1 - s2;
                sectionCnt = &cnt1;
                sectionRows = i + 1;  // top has rows 0..i
            } else {
                diff = s2 - s1;
                sectionCnt = &cnt2;
                sectionRows = m - i - 1;  // bottom has rows i+1..m-1
            }

            if (sectionCnt->count(diff)) {
                // Can we remove a cell with value=diff and keep section connected?
                // A 2D section (rows>1, cols>1): any cell can be removed safely
                // (interior cells fine; corner/edge cells fine unless it's the only cell)
                // A single-row section: only the two endpoint cells are removable
                // A single-col section (n==1): only top and bottom endpoints

                bool canRemove = false;

                if (sectionRows > 1 && n > 1) {
                    // 2D section: any cell is removable
                    canRemove = true;
                } else if (sectionRows == 1) {
                    // Single row: only leftmost or rightmost cell
                    int r = (s1 > s2) ? i : i + 1;
                    canRemove = (g[r][0] == diff || g[r][n - 1] == diff);
                } else {
                    // n==1, single column section: only top or bottom endpoint
                    if (s1 > s2) {
                        // top section: rows 0..i, col 0
                        canRemove = (g[0][0] == diff || g[i][0] == diff);
                    } else {
                        // bottom section: rows i+1..m-1, col 0
                        canRemove = (g[i + 1][0] == diff || g[m - 1][0] == diff);
                    }
                }

                if (canRemove) return true;
            }
        }
        return false;
    }

    vector<vector<int>> rotate(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> r(n, vector<int>(m));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                r[j][i] = g[i][j];  // transpose = vertical → horizontal
        return r;
    }

bool canPartitionGrid(vector<vector<int>>& grid) {
    auto rotated = rotate(grid);
    return check(grid) || check(rotated);
}
};