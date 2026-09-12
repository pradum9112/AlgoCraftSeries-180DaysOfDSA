#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findBound(vector<int>& arr, int target, bool isFirst) {
        int n = arr.size();

        int low = 0;
        int high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                ans = mid;

                if (isFirst) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else if (arr[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

public:
    int countOccurrences(vector<int>& arr, int target) {
        int first = findBound(arr, target, true);

        if (first == -1) {
            return 0;
        }

        int last = findBound(arr, target, false);

        return last - first + 1;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int target = 2;

    cout << sol.countOccurrences(arr, target) << "\n";

    return 0;
}