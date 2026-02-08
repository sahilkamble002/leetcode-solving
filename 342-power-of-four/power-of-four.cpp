class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n == 1){
            return true;
        }
        int x = n;
        if(n > 0 && (n & n-1) == 0 && (x-1) % 3 == 0){
            return true;
        }
        return false;

    }
};