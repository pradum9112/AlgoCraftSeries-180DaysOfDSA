#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void markRow(vector<vector<int>>& matrix, int m, int i) {

        for (int j = 0; j < m; j++) {

            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    void markCol(vector<vector<int>>& matrix, int n, int j) {

        for (int i = 0; i < n; i++) {

            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        // Step 1: Mark rows and columns
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == 0) {

                    markRow(matrix, m, i);
                    markCol(matrix, n, j);
                }
            }
        }

        // Step 2: Convert -1 into 0
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
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