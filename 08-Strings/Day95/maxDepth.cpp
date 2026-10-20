#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int curr_depth = 0;
        int max_depth = 0;

        for (char c : s) {
            if (c == '(') {
                curr_depth++;
                max_depth = max(curr_depth, max_depth);
            } else if (c == ')') {
                curr_depth--;
            }
        }

        return max_depth;
    }
};

int main() {
    Solution solution;

    string s = "(1+(2*3)+((8)/4))+1";

    cout << "Maximum nesting depth: "
         << solution.maxDepth(s) << '\n';

    return 0;
}