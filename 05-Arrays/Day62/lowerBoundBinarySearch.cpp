#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& nums, int x) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 4, 4, 6, 8};
    int x = 4;

    cout << obj.lowerBound(nums, x) << "\n";

    return 0;
}