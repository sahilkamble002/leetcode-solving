class Solution {
public:
    string generateString(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    vector<char> word(n + m - 1, '?');

    // Step 1: Apply 'T' constraints
    for (int i = 0; i < n; i++) {
        if (str1[i] == 'T') {
            for (int j = 0; j < m; j++) {
                if (word[i + j] == '?' || word[i + j] == str2[j]) {
                    word[i + j] = str2[j];
                } else {
                    return "";
                }
            }
        }
    }

    // Step 2: Fill remaining with 'a'
    for (char &c : word) {
        if (c == '?') c = 'a';
    }

    // Step 3: Fix 'F' constraints
    for (int i = 0; i < n; i++) {
        if (str1[i] == 'F') {
            string sub = "";
            for (int j = 0; j < m; j++) {
                sub += word[i + j];
            }

            if (sub == str2) {
                bool changed = false;

                // Try modifying from rightmost
                for (int j = m - 1; j >= 0 && !changed; j--) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == str2[j]) continue;

                        char original = word[i + j];
                        word[i + j] = c;

                        // Validate all 'T' constraints again
                        bool valid = true;
                        for (int k = 0; k < n; k++) {
                            if (str1[k] == 'T') {
                                for (int x = 0; x < m; x++) {
                                    if (word[k + x] != str2[x]) {
                                        valid = false;
                                        break;
                                    }
                                }
                                if (!valid) break;
                            }
                        }

                        if (valid) {
                            changed = true;
                            break;
                        }

                        word[i + j] = original; // revert
                    }
                }

                if (!changed) return "";
            }
        }
    }

    return string(word.begin(), word.end());
    }
};