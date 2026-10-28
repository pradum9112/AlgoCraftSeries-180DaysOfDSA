#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void solve(string &curr_str, int open, int close,
               int n, vector<string> &result) {
        if (curr_str.length() == 2 * n) {
            result.push_back(curr_str);
            return;
        }

        // Add an opening bracket if available
        if (open < n) {
            curr_str.push_back('(');
            solve(curr_str, open + 1, close, n, result);
            curr_str.pop_back();
        }

        // Add a closing bracket only if it stays valid
        if (close < open) {
            curr_str.push_back(')');
            solve(curr_str, open, close + 1, n, result);
            curr_str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr_str = "";

        solve(curr_str, 0, 0, n, result);
        return result;
    }
};

int main() {
    int n;
    cin >> n;

    Solution solution;
    vector<string> result = solution.generateParenthesis(n);

    for (const string &str : result) {
        cout << str << '\n';
    }

    return 0;
}