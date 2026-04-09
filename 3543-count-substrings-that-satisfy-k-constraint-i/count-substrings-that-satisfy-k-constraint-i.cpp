class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
     int n = s.size();
    int result = 0;
    int cnt[2] = {0, 0}; 
    int l = 0;

    for (int r = 0; r < n; r++) {
        cnt[s[r] - '0']++;

        while (cnt[0] > k && cnt[1] > k) {
            cnt[s[l] - '0']--;
            l++;
        }


        result += r - l + 1;
    }

    return result;   
    }
};