#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sum_func(vector<int>& nums, int divisor) {
        int sum = 0;

        for (int num : nums) {
            sum += (num + divisor - 1) / divisor;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int limit) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (sum_func(nums, mid) <= limit) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    int n, limit;
    cin >> n >> limit;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    cout << obj.smallestDivisor(nums, limit) << endl;

    return 0;
}