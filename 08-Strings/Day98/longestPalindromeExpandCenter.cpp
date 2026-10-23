#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int expandFromCenter(const string& s, int left, int right) {
        while (left >= 0 &&
               right < static_cast<int>(s.length()) &&
               s[left] == s[right]) {
            left--;
            right++;
        }

        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < static_cast<int>(s.length()); i++) {
            // Odd-length palindrome
            int len1 = expandFromCenter(s, i, i);

            // Even-length palindrome
            int len2 = expandFromCenter(s, i, i + 1);

            int len = max(len1, len2);

            if (len > end - start + 1) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};

int main() {
    Solution solution;

    cout << solution.longestPalindrome("babad") << '\n';
    cout << solution.longestPalindrome("cbbd") << '\n';
    cout << solution.longestPalindrome("a") << '\n';
    cout << solution.longestPalindrome("") << '\n';

    return 0;
}