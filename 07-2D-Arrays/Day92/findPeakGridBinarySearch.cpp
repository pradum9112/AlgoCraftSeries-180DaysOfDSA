#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int lowCol = 0;
        int highCol = m - 1;

        while (lowCol <= highCol) {
            int midCol = lowCol + (highCol - lowCol) / 2;

            // Find the maximum element in the middle column.
            int maxRow = 0;

            for (int i = 1; i < n; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int current = mat[maxRow][midCol];

            int leftVal = (midCol > 0)
                ? mat[maxRow][midCol - 1] : -1;

            int rightVal = (midCol + 1 < m)
                ? mat[maxRow][midCol + 1] : -1;

            if (current > leftVal && current > rightVal) {
                return {maxRow, midCol};
            }
            else if (leftVal > current) {
                highCol = midCol - 1;
            }
            else {
                lowCol = midCol + 1;
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