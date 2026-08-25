                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLen(vector<int>& arr) {

        unordered_map<int, int> mpp;

        int max_len = 0;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {

            sum += arr[i];

            // Case 1:
            // Prefix sum itself is zero
            if (sum == 0) {
                max_len = i + 1;
            }

            // Case 2:
            // Same prefix sum appeared before
            else if (mpp.find(sum) != mpp.end()) {

                int len = i - mpp[sum];

                max_len = max(max_len, len);
            }

            // Store only first occurrence
            else {
                mpp[sum] = i;
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