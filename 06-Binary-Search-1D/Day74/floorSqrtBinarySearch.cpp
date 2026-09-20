#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int floorSqrt(int n) {
        int low = 0;
        int high = n;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (1LL * mid * mid <= n) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;

    cout << obj.floorSqrt(n) << endl;

    return 0;
}