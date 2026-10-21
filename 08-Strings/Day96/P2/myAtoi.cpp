#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Determine the sign
        int sign = 1;

        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // Step 3: Read digits and check overflow
        long long ans = 0;

        long long limit = (sign == 1)
                          ? INT_MAX
                          : -(long long)INT_MIN;

        while (i < n && isdigit(static_cast<unsigned char>(s[i]))) {
            int digit = s[i] - '0';

            if (ans > (limit - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        // Step 4: Apply sign
        return static_cast<int>(ans * sign);
    }
};

int main() {
    Solution solution;

    cout << solution.myAtoi("42") << '\n';
    cout << solution.myAtoi("   -42") << '\n';
    cout << solution.myAtoi("4193 with words") << '\n';
    cout << solution.myAtoi("words and 987") << '\n';
    cout << solution.myAtoi("2147483648") << '\n';
    cout << solution.myAtoi("-2147483648") << '\n';

    return 0;
}