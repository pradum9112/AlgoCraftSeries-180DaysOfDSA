#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool checkMinOfMAx(vector<int> &nums, int mid, int m) {
        int countStudent = 1;
        int currentPages = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mid) return false;

            if (currentPages + nums[i] > mid) {
                countStudent++;
                currentPages = nums[i];
            } else {
                currentPages += nums[i];
            }
        }

        return countStudent <= m;
    }

    int findPages(vector<int> &nums, int m) {
        int n = nums.size();

        if (m > n) return -1;

        int low = 0;
        int high = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > low) low = nums[i];
            high += nums[i];
        }

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (checkMinOfMAx(nums, mid, m)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};