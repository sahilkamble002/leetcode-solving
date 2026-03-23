class Solution {
public:
    int longestPalindrome(string s) {
    unordered_map<char, int> freq;
    
    for (char c : s) freq[c]++;
    
    int length = 0;
    bool hasOdd = false;
    
    for (auto &p : freq) {
        int count = p.second;
        
        length += (count / 2) * 2;
        
        if (count % 2 == 1) {
            hasOdd = true;
        }
    }
    
    if (hasOdd) length += 1;
    
    return length;
    }
};