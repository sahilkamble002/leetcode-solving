class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        long long ans = 0;
        int n = x;

        while( n > 0){
            int digit = n % 10;
            ans = ans *10 + digit;
            n = n/10;
        }

        if(ans == x){
            return true;
        }
        return false;

    }
};