#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchInARotatedSortedArrayII(vector<int>& nums, int k) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Target found
            if (nums[mid] == k) {
                return true;
            }

            // Duplicate ambiguity:
            // We cannot determine which half is sorted.
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {

                // Target lies in sorted left half
                if (nums[low] <= k && k < nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            // Right half is sorted
            else {

                // Target lies in sorted right half
                if (nums[mid] < k && k <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int k = 0;

    cout << boolalpha << sol.searchInARotatedSortedArrayII(nums, k) << "\n";

    return 0;
}