#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {

        int n = nums.size();

        int repeating = -1;
        int missing = -1;

        // freq[i] stores how many times number i appears
        vector<int> freq(n + 1, 0);

        // Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        // Find repeating and missing
        for (int i = 1; i <= n; i++) {

            if (freq[i] == 2) {
                repeating = i;
            }
            else if (freq[i] == 0) {
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