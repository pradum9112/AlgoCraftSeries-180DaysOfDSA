#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getVal(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int currentVal = getVal(s[i]);

            if (i + 1 < n &&
                currentVal < getVal(s[i + 1])) {
                total -= currentVal;
            } else {
                total += currentVal;
            }
        }

        return total;
    }
};

int main() {
    Solution solution;

    string s = "MCMXCIV";

    cout << solution.romanToInt(s) << '\n';

    return 0;
}