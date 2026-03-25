class Solution {
public:
vector<int> computeLPS(string s) {
    int n = s.size();
    vector<int> lps(n, 0);

    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = lps[j - 1];
        }

        if (s[i] == s[j]) j++;

        lps[i] = j;
    }

    return lps;
}

    string shortestPalindrome(string s) {
         string rev = s;
    reverse(rev.begin(), rev.end());

    string temp = s + "#" + rev;

    vector<int> lps = computeLPS(temp);

    int len = lps.back();  // longest palindrome prefix

    string add = rev.substr(0, s.size() - len);

    return add + s;
    }
};