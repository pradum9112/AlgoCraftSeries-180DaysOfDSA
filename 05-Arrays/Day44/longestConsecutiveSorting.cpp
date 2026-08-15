#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        if (n == 0)
            return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int currentStreak = 1;

        for (int i = 1; i < n; i++) {

            // Duplicate element
            if (nums[i] == nums[i - 1]) {
                continue;
            }

            // Consecutive element
            if (nums[i] == nums[i - 1] + 1) {
                currentStreak++;
            }
            else {
                currentStreak = 1;
            }

            longest = max(longest, currentStreak);
        }

        return longest;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;

    cout << obj.longestConsecutive(nums);

    return 0;
}