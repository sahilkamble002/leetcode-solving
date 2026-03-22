class Solution {
public:
    string getCount(int x) {
        string s = to_string(x);
        vector<int> count(10, 0);
        
        for (char c : s) {
            count[c - '0']++;
        }
        
        string res = "";
        for (int i = 0; i < 10; i++) {
            res += to_string(count[i]) + "#";
        }
        
        return res;
    }
    bool reorderedPowerOf2(int n) {
         string target = getCount(n);
        
        for (int i = 0; i < 31; i++) {
            int power = 1 << i;
            if (getCount(power) == target) {
                return true;
            }
        }
        
        return false;
    }
};