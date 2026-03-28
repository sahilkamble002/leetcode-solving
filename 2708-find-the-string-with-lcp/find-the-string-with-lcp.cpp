class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string word(n, '\0');

        // Step 1: Greedily assign smallest possible character to each position
        char ch = 'a';
        for (int i = 0; i < n; i++) {
            if (word[i] != '\0') continue;
            if (ch > 'z') return "";
            for (int j = i; j < n; j++) {
                if (lcp[i][j] > 0) word[j] = ch;
            }
            ch++;
        }

        // Step 2: Validate against the lcp matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int expected;
                if (word[i] == word[j]) {
                    expected = 1 + ((i+1 < n && j+1 < n) ? lcp[i+1][j+1] : 0);
                } else {
                    expected = 0;
                }
                if (lcp[i][j] != expected) return "";
            }
        }

        return word;
    }
};