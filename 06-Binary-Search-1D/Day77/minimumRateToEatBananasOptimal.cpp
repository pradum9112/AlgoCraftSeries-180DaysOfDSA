#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int TotalHourSumOfKokoEatingBanana(vector<int>& nums, int speed) {
        int totalHourSum = 0;

        for (int num : nums) {
            totalHourSum += (num + speed - 1) / speed;
        }

        return totalHourSum;
    }

    int minimumRateToEatBananas(vector<int> nums, int h) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (TotalHourSumOfKokoEatingBanana(nums, mid) <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};