class Solution {
public:
typedef long long ll;
const ll NEG_INF = LLONG_MIN / 2;
    long long maximumScore(vector<vector<int>>& grid) {
         int n = grid.size();

        // pre[j][r] = sum of col j rows 0..r-1
        vector<vector<ll>> pre(n, vector<ll>(n + 1, 0));
        for (int j = 0; j < n; j++)
            for (int r = 0; r < n; r++)
                pre[j][r+1] = pre[j][r] + grid[r][j];

        // colSum(j, lo, hi) = sum of grid[lo..hi][j], 0 if lo>hi or out of range
        auto colSum = [&](int j, int lo, int hi) -> ll {
            if (lo > hi || j < 0 || j >= n) return 0;
            lo = max(lo, 0); hi = min(hi, n-1);
            if (lo > hi) return 0;
            return pre[j][hi+1] - pre[j][lo];
        };

        // Cuts range: -1 (no black) to n-1. Use +1 offset: index = cut+1, range [0, n].
        int SZ = n + 1;

        // dp[p][c] = best score for cols processed so far,
        //            where p = cut[j-1]+1, c = cut[j]+1 (current col j)
        vector<vector<ll>> dp(SZ, vector<ll>(SZ, NEG_INF));

        // j=0: left neighbor doesn't exist → prev = -1 (index 0), any curr
        for (int c = 0; c < SZ; c++) dp[0][c] = 0;

        for (int j = 0; j < n - 1; j++) {
            // We want: ndp[c][ne] = max over p of:
            //   dp[p][c] + colSum(j, c, max(p-1, ne-1))  [c = curr+1, p = prev+1, ne = next+1]
            //   = dp[p][c] + colSum(j, c, max(p, ne) - 1)
            //
            // Let P=p-1 (prev), C=c-1 (curr), NE=ne-1 (next), all in [-1,n-1]
            // ndp[C+1][NE+1] = max_P { dp[P+1][C+1] + colSum(j, C+1, max(P,NE)) }
            //
            // Case A: NE >= P  → contribution = colSum(j, C+1, NE) [indep of P]
            //   = colSum(j, C+1, NE) + max_{P <= NE} dp[P+1][C+1]
            //
            // Case B: P > NE  → contribution = colSum(j, C+1, P) [indep of NE]
            //   = max_{P > NE} { dp[P+1][C+1] + colSum(j, C+1, P) }

            // For each C, precompute:
            //   prefMaxDP[C][k] = max of dp[P+1][C+1] for P in [-1..k]  (k from -1 to n-1)
            //   sufMaxG[C][k]   = max of (dp[P+1][C+1] + colSum(j, C+1, P)) for P in [k..n-1]

            // Store as arrays indexed [0..n] for P+1
            vector<vector<ll>> prefMaxDP(SZ, vector<ll>(SZ, NEG_INF));
            vector<vector<ll>> sufMaxG(SZ, vector<ll>(SZ, NEG_INF));

            for (int C = -1; C < n; C++) {
                int ci = C + 1;
                // prefix max of dp[P+1][ci] for P = -1..n-1
                for (int P = -1; P < n; P++) {
                    ll v = dp[P+1][ci];
                    prefMaxDP[ci][P+1] = (P == -1) ? v : max(prefMaxDP[ci][P], v);
                }
                // suffix max of G(P,C) = dp[P+1][ci] + colSum(j, C+1, P)
                for (int P = n-1; P >= -1; P--) {
                    ll dpv = dp[P+1][ci];
                    ll g = (dpv == NEG_INF) ? NEG_INF : dpv + colSum(j, C+1, P);
                    sufMaxG[ci][P+1] = (P == n-1) ? g : max(sufMaxG[ci][P+2], g);
                }
            }

            vector<vector<ll>> ndp(SZ, vector<ll>(SZ, NEG_INF));
            for (int C = -1; C < n; C++) {
                int ci = C + 1;
                for (int NE = -1; NE < n; NE++) {
                    // Case A: P <= NE
                    ll caseA = NEG_INF;
                    if (prefMaxDP[ci][NE+1] != NEG_INF)
                        caseA = prefMaxDP[ci][NE+1] + colSum(j, C+1, NE);

                    // Case B: P > NE → P in [NE+1, n-1]
                    ll caseB = NEG_INF;
                    if (NE + 1 < n) // there exist P > NE
                        caseB = sufMaxG[ci][(NE+1)+1]; // P+1 index = NE+2

                    ndp[ci][NE+1] = max(caseA, caseB);
                }
            }
            dp = ndp;
        }

        // Finalize last col (j = n-1): right neighbor = -1 (NE = -1)
        // colSum(n-1, C+1, max(P, -1)) = colSum(n-1, C+1, P)  [P >= -1 always]
        ll ans = 0;
        for (int P = -1; P < n; P++) {
            for (int C = -1; C < n; C++) {
                ll v = dp[P+1][C+1];
                if (v == NEG_INF) continue;
                ans = max(ans, v + colSum(n-1, C+1, P));
            }
        }
        return ans;
    }
};