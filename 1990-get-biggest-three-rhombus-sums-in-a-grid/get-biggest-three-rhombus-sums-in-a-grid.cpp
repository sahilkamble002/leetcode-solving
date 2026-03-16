class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
               int m = grid.size();
        int n = grid[0].size();
        set<int> sums;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                // k = 0 rhombus (single cell)
                sums.insert(grid[i][j]);

                for(int k = 1; ; k++){
                    if(i-k < 0 || i+k >= m || j-k < 0 || j+k >= n)
                        break;

                    int total = 0;

                    for(int d = 0; d < k; d++){
                        total += grid[i-k+d][j+d];      // top -> right
                        total += grid[i+d][j+k-d];      // right -> bottom
                        total += grid[i+k-d][j-d];      // bottom -> left
                        total += grid[i-d][j-k+d];      // left -> top
                    }

                    sums.insert(total);
                }
            }
        }

        vector<int> result(sums.begin(), sums.end());
        sort(result.begin(), result.end(), greater<int>());

        if(result.size() > 3)
            result.resize(3);

        return result;
    }
};