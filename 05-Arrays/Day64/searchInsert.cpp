#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] >= target)
                return i;
        }

        return n;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    cout << obj.searchInsert(nums, target) << "\n";

    return 0;
}