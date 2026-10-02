#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n = a.size();
        int m = b.size();

        // Binary Search hamesha chhote array par lagayenge
        if (n > m) {
            return kthElement(b, a, k);
        }

        // 'a' se kitne elements left partition mein aa sakte hain
        int low = max(0, k - m);

        // 'a' se maximum k elements hi le sakte hain
        int high = min(k, n);

        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = k - mid1;

            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if (mid1 < n) r1 = a[mid1];
            if (mid2 < m) r2 = b[mid2];

            if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

            // Correct partition
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }

            // A se bahut zyada elements le liye
            else if (l1 > r2) {
                high = mid1 - 1;
            }

            // A se aur elements lene hain
            else {
                low = mid1 + 1;
            }
        }

        return 0;
    }
};