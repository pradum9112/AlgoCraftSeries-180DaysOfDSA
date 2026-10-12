#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        stack<char> st;

        for (char c : s) {
            if (c == '(') {
                // If the stack is non-empty, this is not outermost.
                if (!st.empty()) {
                    result += c;
                }

                st.push(c);
            } else {
                st.pop();

                // If the stack is non-empty, this is not outermost.
                if (!st.empty()) {
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