class Solution {
public:
    int rotatedDigits(int n) {
        int rotate[] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
        int count = 0;
        
        for (int x = 1; x <= n; x++) {
            bool valid = true;
            bool different = false;
            int temp = x;
            
            while (temp > 0) {
                int digit = temp % 10;
                if (rotate[digit] == -1) { valid = false; break; }
                if (rotate[digit] != digit) different = true;
                temp /= 10;
            }
            
            if (valid && different) count++;
        }
        
        return count;
    }
};