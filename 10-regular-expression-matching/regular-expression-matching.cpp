class Solution {
public:
 int dp[21][21];

    bool solve(string &s, string &p, int i, int j) {
        if (j == p.size()) return i == s.size();

        if (dp[i][j] != -1) return dp[i][j];

        bool match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            // 2 options:
            // 1. skip "x*"
            // 2. use it if match
            return dp[i][j] = (solve(s, p, i, j + 2) ||
                               (match && solve(s, p, i + 1, j)));
        } else {
            return dp[i][j] = (match && solve(s, p, i + 1, j + 1));
        }
    }
    bool isMatch(string s, string p) {
         memset(dp, -1, sizeof(dp));
        return solve(s, p, 0, 0);
    }
};