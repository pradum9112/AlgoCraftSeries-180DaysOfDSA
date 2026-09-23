#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int TotalHourSumOfKokoEatingBanana(vector<int>& nums, int speed) {
        int totalHour = 0;

        for (int num : nums) {
            totalHour += (num + speed - 1) / speed;
        }

        return totalHour;
    }

    int minimumRateToEatBananas(vector<int> nums, int h) {
        int max_val = *max_element(nums.begin(), nums.end());

        for (int i = 1; i <= max_val; i++) {
            if (TotalHourSumOfKokoEatingBanana(nums, i) <= h) {
                return i;
            }
        }

        return -1;
    }
};