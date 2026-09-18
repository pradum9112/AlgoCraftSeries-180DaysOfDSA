#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {

            // Agar current search space sorted hai,
            // to arr[low] hi minimum hoga.
            if (arr[low] <= arr[high]) {
                ans = min(ans, arr[low]);
                break;
            }

            int mid = low + (high - low) / 2;

            // Left half sorted hai
            if (arr[low] <= arr[mid]) {
                ans = min(ans, arr[low]);

                // Left half ka minimum mil chuka,
                // ab right half search karo.
                low = mid + 1;
            }
            // Right half sorted hai
            else {
                ans = min(ans, arr[mid]);

                // Minimum left half me ho sakta hai.
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;

    cout << obj.findMin(arr) << endl;

    return 0;
}