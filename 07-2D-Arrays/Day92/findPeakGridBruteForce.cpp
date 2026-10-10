#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int current = mat[i][j];

                int top = (i > 0) ? mat[i - 1][j] : -1;
                int bottom = (i + 1 < n) ? mat[i + 1][j] : -1;
                int left = (j > 0) ? mat[i][j - 1] : -1;
                int right = (j + 1 < m) ? mat[i][j + 1] : -1;

                if (current > top &&
                    current > bottom &&
                    current > left &&
                    current > right) {
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    vector<int> ans = sol.findPeakGrid(mat);

    cout << "[" << ans[0] << ", " << ans[1] << "]\n";
    return 0;
}