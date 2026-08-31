#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        int n = nums.size();

        int repeating = -1;
        int missing = -1;

        // Check every number from 1 to n
        for (int i = 1; i <= n; i++) {

            int count = 0;

            // Count frequency of i
            for (int j = 0; j < n; j++) {

                if (nums[j] == i) {
                    count++;
                }
            }

            if (count == 2) {
                repeating = i;
            }
            else if (count == 0) {
                missing = i;
            }
        }

        return {repeating, missing};
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

    vector<int> ans = obj.findMissingRepeatingNumbers(nums);

    cout << "Repeating: " << ans[0] << endl;
    cout << "Missing: " << ans[1] << endl;

    return 0;
}