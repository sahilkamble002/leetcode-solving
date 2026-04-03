class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MOD = 1e9 + 7;


        vector<int> xs, ys;
        for (auto& r : rectangles) {
            xs.push_back(r[0]); xs.push_back(r[2]);
            ys.push_back(r[1]); ys.push_back(r[3]);
        }
        sort(xs.begin(), xs.end()); xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end()); ys.erase(unique(ys.begin(), ys.end()), ys.end());

        
        long long ans = 0;

        for (int i = 0; i + 1 < (int)xs.size(); i++) {
            long long x1 = xs[i], x2 = xs[i + 1];

            
            vector<pair<int,int>> intervals;
            for (auto& r : rectangles) {
                if (r[0] <= x1 && x2 <= r[2]) {       
                    intervals.push_back({r[1], r[3]});
                }
            }

            
            sort(intervals.begin(), intervals.end());
            long long y_cover = 0;
            int cur_y1 = -1, cur_y2 = -1;
            for (auto& [a, b] : intervals) {
                if (a > cur_y2) {                      
                    y_cover += cur_y2 - cur_y1;
                    cur_y1 = a; cur_y2 = b;
                } else {
                    cur_y2 = max(cur_y2, b);           
                }
            }
            y_cover += cur_y2 - cur_y1;               

            ans = (ans + (x2 - x1) % MOD * (y_cover % MOD)) % MOD;
        }

        return (int)ans;

    }
};