class Solution {
public:

    int m, n;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int containVirus(vector<vector<int>>& isInfected) {
        m = isInfected.size();
        n = isInfected[0].size();
        int totalWalls = 0;

        while (true) {
            vector<vector<pair<int,int>>> regions;
            vector<set<pair<int,int>>> frontiers;
            vector<int> walls;
            vector<vector<bool>> visited(m, vector<bool>(n, false));

            // 1. Find all regions
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {
                        vector<pair<int,int>> cells;
                        set<pair<int,int>> frontier;
                        int wall = 0;

                        dfs(isInfected, i, j, visited, cells, frontier, wall);

                        regions.push_back(cells);
                        frontiers.push_back(frontier);
                        walls.push_back(wall);
                    }
                }
            }

            if (regions.empty()) break;

            // 2. Find region with max frontier
            int idx = 0;
            for (int i = 1; i < frontiers.size(); i++) {
                if (frontiers[i].size() > frontiers[idx].size()) {
                    idx = i;
                }
            }

            // If no region can spread
            if (frontiers[idx].empty()) break;

            // 3. Add walls
            totalWalls += walls[idx];

            // 4. Quarantine chosen region
            for (auto &cell : regions[idx]) {
                isInfected[cell.first][cell.second] = -1;
            }

            // 5. Spread other regions
            for (int i = 0; i < regions.size(); i++) {
                if (i == idx) continue;

                for (auto &cell : frontiers[i]) {
                    isInfected[cell.first][cell.second] = 1;
                }
            }
        }

        return totalWalls;
    }
    void dfs(vector<vector<int>>& isInfected, int i, int j,
             vector<vector<bool>>& visited,
             vector<pair<int,int>>& cells,
             set<pair<int,int>>& frontier,
             int &wall) {

        visited[i][j] = true;
        cells.push_back({i,j});

        for (auto &d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;

            if (isInfected[ni][nj] == 0) {
                wall++;
                frontier.insert({ni,nj});
            } 
            else if (isInfected[ni][nj] == 1 && !visited[ni][nj]) {
                dfs(isInfected, ni, nj, visited, cells, frontier, wall);
            }
        }
    }
};