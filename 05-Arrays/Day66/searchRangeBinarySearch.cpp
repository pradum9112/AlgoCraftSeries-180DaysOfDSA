#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findBound(vector<int>& nums, int target, bool isFirst) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;

                if (isFirst) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);

        if (first == -1) {
            return {-1, -1};
        }

        int last = findBound(nums, target, false);

        return {first, last};
    }
};

int main() {
    Solution sol;

    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = sol.searchRange(nums, target);

    cout << "[" << result[0] << ", " << result[1] << "]\n";

    return 0;
}