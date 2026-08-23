#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        int n = nums.size();

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix one element
        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate starting elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            // Step 3: Two pointer
            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // Found a triplet
                if (sum == 0) {

                    ans.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    // Skip duplicate left values
                    while (left < right &&
                           nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // Skip duplicate right values
                    while (left < right &&
                           nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }

                // Sum is too small
                else if (sum < 0) {
                    left++;
                }

                // Sum is too large
                else {
                    right--;
                }
            }
        }

        return ans;
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

    vector<vector<int>> result = obj.threeSum(nums);

    // Print every triplet on a separate line
    for (auto triplet : result) {

        for (int x : triplet) {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}