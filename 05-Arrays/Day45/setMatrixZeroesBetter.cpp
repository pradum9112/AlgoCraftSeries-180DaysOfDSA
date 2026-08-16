#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> dummyRow(n, 0);
        vector<int> dummyCol(m, 0);

        // Step 1: Remember which rows and columns contain zero
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == 0) {
                    dummyRow[i] = 1;
                    dummyCol[j] = 1;
                }
            }
        }

        // Step 2: Set marked rows and columns to zero
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (dummyRow[i] == 1 || dummyCol[j] == 1) {
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