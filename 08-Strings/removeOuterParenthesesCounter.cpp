#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                // Append only if already inside a primitive.
                if (balance > 0) {
                    result += c;
                }

                balance++;
            } else {
                balance--;

                // Append only if still inside a primitive.
                if (balance > 0) {
                    result += c;
                }
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