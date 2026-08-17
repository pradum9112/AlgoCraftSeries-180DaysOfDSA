#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>> ans(n, vector<int>(n));

        // Move elements to their rotated positions
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                ans[j][n - 1 - i] = matrix[i][j];
            }
        }

        // Copy rotated matrix back
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                matrix[i][j] = ans[i][j];
            }
        }
    }
};

int main() {

    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution obj;

    obj.rotateMatrix(matrix);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}