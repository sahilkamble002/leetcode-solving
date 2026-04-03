class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        
        vector<pair<int,int>> pairs(n);
        for (int i = 0; i < n; i++) pairs[i] = {robots[i], distance[i]};
        sort(pairs.begin(), pairs.end());

        vector<int> r(n), d(n);
        for (int i = 0; i < n; i++) {
            r[i] = pairs[i].first;
            d[i] = pairs[i].second;
        }

        vector<int> ws = walls;
        sort(ws.begin(), ws.end());
        set<int> walls_set(walls.begin(), walls.end());

        
        auto count_walls = [&](long long lo, long long hi) -> int {
            if (lo > hi) return 0;
            return (int)(upper_bound(ws.begin(), ws.end(), (int)hi) -
                         lower_bound(ws.begin(), ws.end(), (int)lo));
        };

        
        int base = 0;
        for (int pos : r)
            if (walls_set.count(pos)) base++;

        
        int ext_left  = count_walls((long long)r[0]    - d[0],    r[0]    - 1);
        int ext_right = count_walls((long long)r[n-1]  + 1,       (long long)r[n-1] + d[n-1]);


        vector<int> dp = {ext_left, 0};

        for (int i = 1; i < n; i++) {

            long long lo_A = (long long)r[i-1] + 1;
            long long hi_A = min((long long)r[i-1] + d[i-1], (long long)r[i] - 1);
            int R_prev = count_walls(lo_A, hi_A);

            
            long long lo_B = max((long long)r[i] - d[i], (long long)r[i-1] + 1);
            long long hi_B = (long long)r[i] - 1;
            int L_curr = count_walls(lo_B, hi_B);

            
            int both = R_prev + L_curr - count_walls(lo_B, hi_A);

            vector<int> ndp(2);
            ndp[0] = max(dp[0] + L_curr, dp[1] + both);   
            ndp[1] = max(dp[0],          dp[1] + R_prev);  
            dp = ndp;
        }

        return base + max(dp[0], dp[1] + ext_right);
    }
};