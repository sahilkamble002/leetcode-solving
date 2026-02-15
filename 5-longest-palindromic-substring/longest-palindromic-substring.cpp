class Solution {
public:
int expandAroundCenter(string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}
    string longestPalindrome(string s) {
         if (s.empty()) return "";
    
    int start = 0, maxLen = 0;
    
    for (int i = 0; i < s.length(); i++) {
        // Check for odd-length palindromes (center is a single character)
        int len1 = expandAroundCenter(s, i, i);
        // Check for even-length palindromes (center is between two characters)
        int len2 = expandAroundCenter(s, i, i + 1);
        
        int len = max(len1, len2);
        
        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }
    
    return s.substr(start, maxLen);
    }
};