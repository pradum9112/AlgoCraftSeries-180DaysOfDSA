#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }

public:
    string longestPalindrome(string s) {
        int n = s.length();
        string longest = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    int len = j - i + 1;

                    if (len > longest.length()) {
                        longest = s.substr(i, len);
                    }
                }
            }
        }

        return longest;
    }
};

int main() {
    Solution solution;

    cout << solution.longestPalindrome("babad") << '\n';
    cout << solution.longestPalindrome("cbbd") << '\n';

    return 0;
}