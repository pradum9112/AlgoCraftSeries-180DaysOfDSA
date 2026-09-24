#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums, int day, int m, int k) {
        int count = 0;
        int total_bouquets = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= day) {
                count++;

                if (count == k) {
                    total_bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return total_bouquets >= m;
    }

    int roseGarden(int n, vector<int> nums, int k, int m) {
        long long required_flowers = (long long)m * k;

        if (required_flowers > n) {
            return -1;
        }

        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(nums, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};