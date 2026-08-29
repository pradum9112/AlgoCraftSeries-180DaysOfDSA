#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void swapIfGreater(vector<int>& arr1, vector<int>& arr2,
                       int ind1, int ind2) {

        if (arr1[ind1] > arr2[ind2]) {
            swap(arr1[ind1], arr2[ind2]);
        }
    }

    void merge(vector<int>& arr1, vector<int>& arr2) {

        int n = arr1.size();
        int m = arr2.size();

        int len = n + m;

        // Initial gap
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {

            int left = 0;
            int right = left + gap;

            while (right < len) {

                // Case 1:
                // left -> arr1
                // right -> arr2
                if (left < n && right >= n) {

                    swapIfGreater(
                        arr1,
                        arr2,
                        left,
                        right - n
                    );
                }

                // Case 2:
                // left and right dono arr2 me
                else if (left >= n) {

                    swapIfGreater(
                        arr2,
                        arr2,
                        left - n,
                        right - n
                    );
                }

                // Case 3:
                // left and right dono arr1 me
                else {

                    swapIfGreater(
                        arr1,
                        arr1,
                        left,
                        right
                    );
                }

                left++;
                right++;
            }

            // Gap 1 ke baad array sorted ho jayega
            if (gap == 1) {
                break;
            }

            // Next gap
            gap = (gap / 2) + (gap % 2);
        }
    }
};

int main() {

    int n, m;

    cin >> n >> m;

    vector<int> arr1(n);
    vector<int> arr2(m);

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    Solution obj;

    obj.merge(arr1, arr2);

    cout << "arr1: ";

    for (int x : arr1) {
        cout << x << " ";
    }

    cout << endl;

    cout << "arr2: ";

    for (int x : arr2) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}