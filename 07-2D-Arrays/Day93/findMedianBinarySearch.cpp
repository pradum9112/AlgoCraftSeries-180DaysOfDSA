#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int countSmallerThanEqualTo(
        vector<vector<int>>& matrix,
        int mid
    ) {
        int count = 0;

        for (int i = 0; i < matrix.size(); i++) {
            count += upper_bound(
                matrix[i].begin(),
                matrix[i].end(),
                mid
            ) - matrix[i].begin();
        }

        return count;
    }

public:
    int findMedian(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[0][m - 1];

        for (int i = 1; i < n; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }

        int req = (n * m) / 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int count = countSmallerThanEqualTo(matrix, mid);

            if (count <= req) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
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