#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr) {

        int max_len = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {

            int current_sum = 0;

            for (int j = i; j < n; j++) {

                current_sum += arr[j];

                if (current_sum == 0) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }

        return max_len;
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

    cout << obj.maxLen(arr) << endl;

    return 0;
}