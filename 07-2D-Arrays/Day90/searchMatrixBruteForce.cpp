#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == target) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;

    cout << boolalpha << sol.searchMatrix(mat, target) << endl;

    return 0;
}