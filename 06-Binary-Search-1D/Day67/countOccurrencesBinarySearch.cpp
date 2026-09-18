#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int firstSearch(vector<int>& arr, int target) {
        int n = arr.size();

        int low = 0;
        int high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            else if (arr[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return first;
    }

    int lastSearch(vector<int>& arr, int target) {
        int n = arr.size();

        int low = 0;
        int high = n - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            else if (arr[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return last;
    }

public:
    int countOccurrences(vector<int>& arr, int target) {
        int first = firstSearch(arr, target);

        if (first == -1) {
            return 0;
        }

        int last = lastSearch(arr, target);

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