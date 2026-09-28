#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool min_dis(vector<int>& nums, int mid, int k) {
        int cowCount = 1;
        int lastPos = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - lastPos >= mid) {
                lastPos = nums[i];
                cowCount++;
            }

            if (cowCount == k)
                return true;
        }

        return false;
    }

    int aggressiveCows(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int low = 1;
        int high = nums[n - 1] - nums[0];
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (min_dis(nums, mid, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};