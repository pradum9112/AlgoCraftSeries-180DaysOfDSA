#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithXorK(vector<int>& nums, int k) {

        int xr = 0;
        int count = 0;

        unordered_map<int, int> mpp;

        // Base case
        mpp[0] = 1;

        for (int num : nums) {

            // Prefix XOR
            xr = xr ^ num;

            // Required previous XOR
            int x = xr ^ k;

            // Count previous occurrences
            count += mpp[x];

            // Store current prefix XOR
            mpp[xr]++;
        }

        return count;
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

    cout << obj.subarraysWithXorK(nums, k) << endl;

    return 0;
}