class Solution {
public:
    bool isSubsequence(string s, string t) {
            int i = 0, j = 0;

    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++;  // match found, move s pointer
        }
        j++;  // always move t pointer
    }

    return i == s.length();
    }
};