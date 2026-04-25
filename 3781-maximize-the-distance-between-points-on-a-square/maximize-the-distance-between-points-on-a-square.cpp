class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
            int n = points.size();
        long long perim = 4LL * side;
        
        vector<long long> t(n);
        for (int i = 0; i < n; i++) {
            long long x = points[i][0], y = points[i][1];
            if (y == 0)             t[i] = x;              // bottom
            else if (x == side)     t[i] = side + y;        // right
            else if (y == side)     t[i] = 2LL*side + (side - x); // top
            else                    t[i] = 3LL*side + (side - y); // left
        }
        
        sort(t.begin(), t.end());
        
        // Check if we can place k points with min gap >= d (circular)
        // Try each point as the starting point, greedily pick next
        auto canPlace = [&](long long d) -> bool {
            // For each starting index, greedily pick k points
            for (int start = 0; start < n; start++) {
                int count = 1;
                long long cur = t[start];
                long long startVal = t[start];
                int idx = start;
                
                while (count < k) {
                    // Binary search for first t[j] >= cur + d
                    long long need = cur + d;
                    // Search in [idx+1, n-1] then wrap
                    // Use lower_bound on the sorted array
                    int lo = idx + 1, hi = n - 1, found = -1;
                    while (lo <= hi) {
                        int mid = (lo + hi) / 2;
                        if (t[mid] >= need) { found = mid; hi = mid - 1; }
                        else lo = mid + 1;
                    }
                    
                    if (found == -1) break; // no more in linear range
                    
                    idx = found;
                    cur = t[idx];
                    count++;
                }
                
                if (count == k) {
                    // Check wrap-around: distance from last to first (circular)
                    // = perim - cur + startVal >= d
                    if (perim - cur + startVal >= d) return true;
                }
            }
            return false;
        };
        
        // Binary search on answer
        long long lo = 1, hi = perim / k, ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            if (canPlace(mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        
        return (int)ans;
    }
};