#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<long long, int> prefix_map;

        long long current_sum = 0;
        int max_len = 0;

        for (int i = 0; i < n; i++) {

            current_sum += nums[i];

            // Case 1
            if (current_sum == k) {
                max_len = max(max_len, i + 1);
            }

            // Case 2
            long long rem = current_sum - k;

            if (prefix_map.find(rem) != prefix_map.end()) {

                int len = i - prefix_map[rem];
                max_len = max(max_len, len);
            }

            // Case 3
            if (prefix_map.find(current_sum) == prefix_map.end()) {
                prefix_map[current_sum] = i;
            }
        }

        return max_len;
    }
};

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << obj.longestSubarray(nums, k);

    return 0;
}