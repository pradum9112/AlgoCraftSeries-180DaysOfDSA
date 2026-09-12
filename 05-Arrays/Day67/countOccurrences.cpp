#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOccurrences(vector<int>& arr, int target) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == target) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int target = 2;

    cout << sol.countOccurrences(arr, target) << "\n";

    return 0;
}