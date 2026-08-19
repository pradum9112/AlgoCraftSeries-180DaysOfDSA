#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mpp;

        // Prefix sum 0 initially exists once
        mpp[0] = 1;

        int current_sum = 0;
        int count = 0;

        for (int num : nums) {

            current_sum += num;

            int remove = current_sum - k;

            if (mpp.find(remove) != mpp.end()) {
                count += mpp[remove];
            }

            mpp[current_sum]++;
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

    cout << obj.subarraySum(nums, k);

    return 0;
}