#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        // col0 remembers whether first column
        // originally contained a zero
        int col0 = 1;

        // Step 1:
        // Use first row and first column as markers
        for (int i = 0; i < m; i++) {

            if (matrix[i][0] == 0) {
                col0 = 0;
            }

            for (int j = 1; j < n; j++) {

                if (matrix[i][j] == 0) {

                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2:
        // Use markers to make inner matrix zero
        for (int i = 1; i < m; i++) {

            for (int j = 1; j < n; j++) {

                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3:
        // Handle first row
        if (matrix[0][0] == 0) {

            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4:
        // Handle first column
        if (col0 == 0) {

            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution obj;

    obj.setZeroes(matrix);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}