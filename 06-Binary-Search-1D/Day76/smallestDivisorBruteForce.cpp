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
        int max_val = *max_element(nums.begin(), nums.end());

        for (int i = 1; i <= max_val; i++) {
            if (sum_func(nums, i) <= limit) {
                return i;
            }
        }

        return -1;
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