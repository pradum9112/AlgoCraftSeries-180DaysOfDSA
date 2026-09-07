#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int>& nums, int x) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] >= x)
                return i;
        }

        return n;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 4, 4, 6, 8};
    int x = 4;

    cout << obj.lowerBound(nums, x) << "\n";

    return 0;
}