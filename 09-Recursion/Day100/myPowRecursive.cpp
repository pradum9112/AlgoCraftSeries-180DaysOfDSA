#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    double solve(double x, long long n) {
        // Base case
        if (n == 0) {
            return 1.0;
        }

        // Solve for half the power
        double half = solve(x, n / 2);

        // Even power
        if (n % 2 == 0) {
            return half * half;
        }

        // Odd power
        return half * half * x;
    }

public:
    double myPow(double x, int n) {
        long long nn = n;

        if (nn < 0) {
            nn = -nn;
            x = 1.0 / x;
        }

        return solve(x, nn);
    }
};

int main() {
    Solution obj;

    cout << fixed << setprecision(6);
    cout << obj.myPow(2.0, 10) << '\n';
    cout << obj.myPow(2.0, -2) << '\n';
    cout << obj.myPow(2.1, 3) << '\n';
    cout << obj.myPow(2.0, 0) << '\n';

    return 0;
}