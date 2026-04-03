class Solution {
public:
    int findIntegers(int n) {
        vector<int> bits;
        for (int i = 30; i >= 0; i--)
            if ((n >> i) & 1 || !bits.empty())
                bits.push_back((n >> i) & 1);

        int m = bits.size();
        
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(2, vector<int>(2, -1)));

        function<int(int, bool, int)> dp = [&](int pos, bool tight, int prev) -> int {
            if (pos == m) return 1; 

            int t = tight ? 1 : 0;
            if (memo[pos][t][prev] != -1)
                return memo[pos][t][prev];

            int limit = tight ? bits[pos] : 1;
            int res = 0;

            for (int bit = 0; bit <= limit; bit++) {
                if (prev == 1 && bit == 1) continue; 
                res += dp(pos + 1, tight && (bit == limit), bit);
            }

            return memo[pos][t][prev] = res;
        };

        return dp(0, true, 0);
    }
};