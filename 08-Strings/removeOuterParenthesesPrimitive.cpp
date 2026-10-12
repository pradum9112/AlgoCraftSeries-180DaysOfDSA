#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int start = 0;
        int balance = 0;

        for (int i = 0; i < static_cast<int>(s.length()); i++) {
            if (s[i] == '(') {
                balance++;
            } else {
                balance--;
            }

            // A primitive ends when balance returns to zero.
            if (balance == 0) {
                // Remove the first and last parentheses.
                if (i - start > 2) {
                    result += s.substr(start + 1, i - start - 1);
                }

                start = i + 1;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    string s = "(()())(())(()(()))";
    cout << sol.removeOuterParentheses(s) << '\n';

    return 0;
}