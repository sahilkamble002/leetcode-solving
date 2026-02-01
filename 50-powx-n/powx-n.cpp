class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;

    if (n < 0) {
        // handle INT_MIN safely
        if (n == INT_MIN)
            return 1 / (x * myPow(x, -(n + 1)));

        return 1 / myPow(x, -n);
    }

    if (n % 2 == 0) {
        return myPow(x * x, n / 2);
    }

    return x * myPow(x, n - 1);
    }
};