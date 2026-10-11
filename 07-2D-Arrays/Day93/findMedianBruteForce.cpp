#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMedian(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> temp;
        temp.reserve(n * m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp.push_back(matrix[i][j]);
            }
        }

        sort(temp.begin(), temp.end());

        int midIndex = (n * m) / 2;
        return temp[midIndex];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    cout << sol.findMedian(matrix) << '\n';

    return 0;
}