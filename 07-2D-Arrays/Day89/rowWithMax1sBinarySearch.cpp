#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rowWithMax1s(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int maxOnesCount = 0;
        int rowIndex = -1;

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(mat[i].begin(), mat[i].end(), 1);

            int firstOneIndex = it - mat[i].begin();

            int currentOnes = m - firstOneIndex;

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