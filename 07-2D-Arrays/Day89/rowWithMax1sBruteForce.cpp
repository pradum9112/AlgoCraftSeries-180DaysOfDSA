#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rowWithMax1s(vector<vector<int>>& mat) {
        int maxOnesCount = 0;
        int rowIndex = -1;

        for (int i = 0; i < mat.size(); i++) {
            int currentOnes = 0;

            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    currentOnes++;
                }
            }

            if (currentOnes > maxOnesCount) {
                maxOnesCount = currentOnes;
                rowIndex = i;
            }
        }

        return rowIndex;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 0}
    };

    cout << sol.rowWithMax1s(mat) << "\n";

    return 0;
}