#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();

        // Single element
        if (n == 1) return 0;

        // Check last element
        if (arr[n - 1] > arr[n - 2])
            return n - 1;

        // Check every element
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1])
                return i;
        }

        return -1;
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

    int ans = obj.findPeakElement(arr);

    cout << "Peak Element Index: " << ans << endl;
    cout << "Peak Element: " << arr[ans] << endl;

    return 0;
}