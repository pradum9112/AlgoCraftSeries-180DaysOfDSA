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

        for (int i = low; i < high; i++) {
            if (checkMinOfMAx(nums, i, m)) {
                return i;
            }
        }

        return -1;
    }
};