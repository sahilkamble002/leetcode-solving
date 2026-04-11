class Solution {
public:
    int numDecodings(string s) {
                const int MOD = 1e9 + 7;
        int n = s.size();
        
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '*') ? 9 : (s[0] == '0' ? 0 : 1);
        
        for (int i = 2; i <= n; i++) {
            char cur  = s[i-1];
            char prev = s[i-2];
            
            // ── Single character ───────────────────────────────
            if (cur == '*')
                dp[i] = 9 * dp[i-1] % MOD;
            else if (cur != '0')
                dp[i] = dp[i-1];
            
            // ── Two characters ─────────────────────────────────
            if (prev == '*' && cur == '*') {
                // 11-19 (9) + 21-26 (6) = 15
                dp[i] = (dp[i] + 15 * dp[i-2]) % MOD;
            }
            else if (prev == '*') {
                int d = cur - '0';
                long long ways = 0;
                if (d == 0)             ways = 2; // ✅ FIX: 10 and 20 both valid
                else if (d <= 6)        ways = 2; // 1X and 2X both valid
                else                    ways = 1; // only 1X valid (17, 18, 19)
                dp[i] = (dp[i] + ways * dp[i-2]) % MOD;
            }
            else if (cur == '*') {
                if (prev == '1')
                    dp[i] = (dp[i] + 9 * dp[i-2]) % MOD; // 11-19
                else if (prev == '2')
                    dp[i] = (dp[i] + 6 * dp[i-2]) % MOD; // 21-26
            }
            else {
                int two = (prev - '0') * 10 + (cur - '0');
                if (two >= 10 && two <= 26)
                    dp[i] = (dp[i] + dp[i-2]) % MOD;
            }
        }
        
        return dp[n];
    }
};