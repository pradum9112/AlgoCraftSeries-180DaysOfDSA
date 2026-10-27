#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        double ans = 1.0;

        if (nn < 0) {
            nn = -nn;
            x = 1.0 / x;
        }

        while (nn > 0) {
            if (nn % 2 == 1) {
                ans *= x;
                nn--;
            } else {
                x *= x;
                nn /= 2;
            }
        }

        return ans;
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