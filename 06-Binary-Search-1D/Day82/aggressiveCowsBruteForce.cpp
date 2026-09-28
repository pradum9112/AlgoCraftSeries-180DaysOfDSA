#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool min_dis(vector<int>& nums, int dist, int k) {
        int cowCount = 1;
        int lastPos = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - lastPos >= dist) {
                cowCount++;
                lastPos = nums[i];
            }

            if (cowCount == k)
                return true;
        }

        return false;
    }

    int aggressiveCows(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int max_dist = nums[n - 1] - nums[0];

        for (int d = 1; d <= max_dist; d++) {
            if (!min_dis(nums, d, k)) {
                return d - 1;
            }
        }

        return max_dist;
    }
};